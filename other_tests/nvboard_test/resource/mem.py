# 打开文件
with open('mem_shift.txt', 'r') as file:
    # 创建一个256个元素的数组
    array = [0] * 256
    # 逐行读取文件内容
    for line in file:
        # 去除行末尾的换行符
        line = line.strip()
        # 将行内容按空格分割为两个元素
        elements = line.split(' ')
        # 获取ascii字符和16进制数
        ascii_char = elements[0]
        hex_num = elements[1]
        # 将16进制数转换为10进制，并作为数组下标存入ascii字符的ascii值
        array[int(hex_num, 16)] = ord(ascii_char)

# 打印数组内容
print(array)

# 打开文件
with open('mem_shift.hex', 'w') as file:
    file.write(f'@00\n')
    # 逐行输出数组内容
    for i in range(256):
        # 将数组元素转换为2位的十六进制，并写入文件
        file.write(f'{array[i]:02X}\n')