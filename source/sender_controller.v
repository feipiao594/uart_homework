module sender_controller (
    input wire clk,             // 时钟信号
    input wire rst_n,           // 复位信号（低有效）
    input wire s3, s0,          // 选择数据存储位置
    input wire s4, s1,          // 数据调整键
    input wire s2,              // 确认发送
    output reg [7:0] send_data, // 发送数据
    output reg [7:0] preview_data, // 预览数据
    output reg send_signal       // 触发发送信号
);

    reg [2:0] data_index;  // 选择数据存储的位置
    reg [7:0] data_ram [0:7]; // 数据存储器

    // 存储上一个时钟周期的按键状态
    reg s3_prev, s0_prev, s4_prev, s1_prev, s2_prev;

    parallel_to_serial #(.P_WIDTH(IN_WIDTH), .S_WIDTH(OUT_WIDTH)) P2S (
                .clk(clk),
                .rst(rst),
                .load(rd_en),
                .parallel_in(p2s_parallel_in),
                .serial_out(p2s_serial_out),
                .valid(p2s_valid),
                .busy(p2s_busy)
            );

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            data_index   <= 1'b0;
            send_data    <= 8'h00;
            data_ram[0]  <= 8'h00;
            data_ram[1]  <= 8'h00;
            data_ram[2]  <= 8'h00;
            data_ram[3]  <= 8'h00;
            data_ram[4]  <= 8'h00;
            data_ram[5]  <= 8'h00;
            data_ram[6]  <= 8'h00;
            data_ram[7]  <= 8'h00;
            preview_data <= 8'h00;
            send_signal  <= 1'b0;
            s3_prev      <= 1'b0;
            s0_prev      <= 1'b0;
            s4_prev      <= 1'b0;
            s1_prev      <= 1'b0;
            s2_prev      <= 1'b0;
        end else begin
            // 上升沿检测逻辑
            if (s3 && !s3_prev) begin
                data_index <= data_index + 1;  // 选择高 4 位
                preview_data <= data_ram[data_index];
            end
            else if (s0 && !s0_prev) begin
                data_index <= data_index - 1;  // 选择低 4 位
                preview_data <= data_ram[data_index];
            end

            if (s4 && !s4_prev) begin
                data_ram[data_index] <= data_ram[data_index] + 1;
                preview_data <= data_ram[data_index] + 1;
            end 
            else if (s1 && !s1_prev) begin
                data_ram[data_index] <= data_ram[data_index] - 1;
                preview_data <= data_ram[data_index] - 1;
            end

            if (s2 && !s2_prev)
                send_start <= 1'b1; // 触发发送信号
            else
                send_start <= 1'b0; // 仅触发一次，避免连续高电平影响

            // 存储当前按键状态用于下次比较
            s3_prev <= s3;
            s0_prev <= s0;
            s4_prev <= s4;
            s1_prev <= s1;
            s2_prev <= s2;
        end
    end

endmodule
