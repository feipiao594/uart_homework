import argparse
import re

# 读取 Verilog 源文件
def parse_verilog(filename):
    with open(filename, "r") as f:
        lines = f.readlines()

    module_name = ""
    parameters = {}
    ports = []

    in_param_block = False
    in_port_block = False

    matched_num = 0

    for line in lines:
        line = line.strip()

        # 提取 module 名称
        match = re.match(r"module\s+(\w+)", line)
        if match:
            module_name = match.group(1)

        # 提取参数定义
        if "#(" in line:
            in_param_block = True
        if in_param_block:
            match = re.match(r"parameter\s+(\w+)\s*=\s*(\d+)", line)
            if match:
                parameters[match.group(1)] = match.group(2)
        if ")" in line and in_param_block:
            in_param_block = False

        if not in_param_block:
        # 提取端口定义
            match = re.match(r"(input|output|inout)\s+(wire|reg)?\s*(\[.*?\])?\s*(\w+)", line)
            if match:
                direction, type, bit_width, name = match.groups()
                matched_num = 1
                if bit_width is None:
                    bit_width = ""
                if type is None:
                    type = ""
                ports.append((direction, type, bit_width, name))


        if ";" in line:
            break
    if matched_num == 0:
       print("[ERROR] No ports found in the module, check your module pins if they are defined with input/output/inout")
       exit(1)

    return module_name, parameters, ports

# 生成 top.v
def generate_top(module_name, parameters, ports, output_filename="top.v"):
    top_module_name = "top"

    # 生成端口定义
    port_definitions = []
    for direction, type, bit_width, name in ports:
        temp_bit_width = bit_width
        for p_name, value in parameters.items():
            if(p_name in temp_bit_width):
                # print(f"[INFO] Replace {p_name} with {value}")
                temp_bit_width = temp_bit_width.replace(p_name, value)
        port_line = f"    {direction} {type} {temp_bit_width} {name},".strip(",")
        port_definitions.append(port_line)

    # 生成实例化部分
    instance_ports = []
    for _, _, _, name in ports:
        instance_ports.append(f"        .{name}({name})")

    # 生成参数定义
    parameter_definitions = []
    for name, value in parameters.items():
        parameter_definitions.append(f".{name}({value})")

    # 生成 Verilog 文件
    with open(output_filename, "w") as f:
        f.write(f"module {top_module_name}(\n")
        f.write(",\n".join(port_definitions) + "\n")
        f.write("    );\n\n")

        f.write(f"    {module_name}")

        if len(parameter_definitions) > 0:
            f.write(" #(")
            f.write(",".join(parameter_definitions))
            f.write(")")

        f.write(f" m_{module_name}(\n")
        f.write(",\n".join(instance_ports) + "\n")
        f.write("    );\n\n")

        f.write("endmodule\n")

    print(f"[INFO] Extract {output_filename} success")

# 主函数
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="auto parse *.v -> top.v")
    parser.add_argument("input_file", type=str, help="input verilog file path")
    parser.add_argument("output_file", type=str, help="output verilog file path")

    args = parser.parse_args()

    # 解析 Verilog 文件
    module_name, parameters, ports = parse_verilog(args.input_file)

    # 生成 top.v
    generate_top(module_name, parameters, ports, args.output_file)
