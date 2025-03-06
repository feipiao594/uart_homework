module baudrate_generator (
    input wire clk,          // 系统时钟信号
    input wire rst_n,        // 复位信号
    input wire [31:0] clk_freq,  // 输入的时钟频率（单位：Hz）
    output reg baud_tick     // 触发信号，每次触发表示发送/接收一个 bit
);

    parameter TARGET_BAUD = 115200;  // 目标波特率（115200 bps）
    reg [31:0] baud_div;      // 动态分频系数
    reg [31:0] counter;       // 计数器

    // 根据时钟频率和目标波特率动态计算分频系数
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            baud_div <= 0;
            counter <= 0;
            baud_tick <= 0;
        end else begin
            // 计算波特率分频系数
            baud_div <= clk_freq / TARGET_BAUD;  // 分频系数 = 时钟频率 / 目标波特率

            // 波特率发生器逻辑
            if (counter == baud_div - 1) begin
                counter <= 0;
                baud_tick <= 1'b1;  // 触发波特率时钟
            end else begin
                counter <= counter + 1;
                baud_tick <= 1'b0;
            end
        end
    end
endmodule
