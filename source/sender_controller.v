module sender_controller (
    input wire clk,             // 时钟信号
    input wire rst_n,           // 复位信号（低有效）
    input wire s3, s0,          // 选择数据存储位置（高4位 or 低4位）
    input wire s4, s1,          // 数据调整键
    input wire s2,              // 确认发送
    output reg [7:0] send_data, // 8 位发送数据
    output reg send_start      // 触发发送信号
);

    reg data_index;  // 选择数据存储的位置 (0 低4位, 1 高4位)

    // 存储上一个时钟周期的按键状态
    reg s3_prev, s0_prev, s4_prev, s1_prev, s2_prev;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            data_index   <= 1'b0;
            send_data    <= 8'h00;
            send_start  <= 1'b0;
            s3_prev      <= 1'b0;
            s0_prev      <= 1'b0;
            s4_prev      <= 1'b0;
            s1_prev      <= 1'b0;
            s2_prev      <= 1'b0;
        end else begin
            // 上升沿检测逻辑
            if (s3 && !s3_prev) 
                data_index <= 1'b1;  // 选择高 4 位
            if (s0 && !s0_prev) 
                data_index <= 1'b0;  // 选择低 4 位
            
            if (s4 && !s4_prev) begin
                if (data_index)
                    send_data[7:4] <= send_data[7:4] + 1; // 高 4 位递增
                else
                    send_data[3:0] <= send_data[3:0] + 1; // 低 4 位递增
            end 

            if (s1 && !s1_prev) begin
                if (data_index)
                    send_data[7:4] <= send_data[7:4] - 1; // 高 4 位递减
                else
                    send_data[3:0] <= send_data[3:0] - 1; // 低 4 位递减
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
