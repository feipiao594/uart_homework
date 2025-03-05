module serial_to_parallel #(
    parameter S_WIDTH = 8,   // 串行输入数据位宽
    parameter P_WIDTH = 64   // 并行输出数据位宽
)(
    input wire clk,          // 时钟信号
    input wire rst,          // 复位信号
    input wire load,         // 使能加载串行数据
    input wire [S_WIDTH-1:0] serial_in, // 串行输入数据
    output reg [P_WIDTH-1:0] parallel_out, // 并行输出数据
    output reg valid,        // 并行数据有效信号
    output reg ready         // 是否可以继续接收串行数据
);

    localparam COUNT_MAX = P_WIDTH / S_WIDTH; // 需要多少次串行输入才能填满并行数据

    reg [P_WIDTH-1:0] shift_reg;   // 移位寄存器
    reg [$clog2(COUNT_MAX)-1 :0] counter; // 计数器

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            shift_reg <= 0;
            counter <= 0;
            parallel_out <= 0;
            valid <= 0;
            ready <= 1;
        end 
        else if (load && ready) begin
            // 右移 S_WIDTH 位，并插入新数据
            shift_reg <= {shift_reg[P_WIDTH-S_WIDTH-1:0], serial_in};
            counter <= counter + 1;

            // 当数据填满 `P_WIDTH` 时，输出并行数据
            if (counter == COUNT_MAX - 1) begin
                parallel_out <= {shift_reg[P_WIDTH-S_WIDTH-1:0], serial_in};
                valid <= 1; // 数据有效
                counter <= 0; // 重新计数
            end
            else begin
                valid <= 0; // 数据未满，不输出
            end
        end
    end

endmodule
