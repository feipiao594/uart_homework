`timescale 1ns / 1ps

module sender_controller_tb;

    // 信号定义
    reg rst_n;
    reg s3, s0;       // 选择数据存储位置
    reg s4, s1;       // 数据调整键
    reg s2;           // 发送确认
    wire [7:0] send_data;  // 发送的数据
    wire send_enable;      // 发送触发信号

    // 实例化被测模块 (DUT)
    sender_controller uut (
        .rst_n(rst_n),
        .s3(s3),
        .s0(s0),
        .s4(s4),
        .s1(s1),
        .s2(s2),
        .send_data(send_data),
        .send_enable(send_enable)
    );

    // 测试逻辑
    initial begin
        // 初始化信号
        rst_n = 0;
        s3 = 0; s0 = 0;
        s4 = 0; s1 = 0;
        s2 = 0;
        #10; // 等待 10 ns 释放复位

        rst_n = 1;  // 释放复位
        #10;

        // 选择高 4 位
        s3 = 1; #10; s3 = 0; #10;
        
        // 递增高 4 位 (0x00 -> 0x10)
        s4 = 1; #10; s4 = 0; #10;

        // 选择低 4 位
        s0 = 1; #10; s0 = 0; #10;

        // 递增低 4 位 (0x10 -> 0x11)
        s4 = 1; #10; s4 = 0; #10;
        s4 = 1; #10; s4 = 0; #10;

        // 递减低 4 位 (0x11 -> 0x10)
        s1 = 1; #10; s1 = 0; #10;

        // 触发发送
        s2 = 1; #10; s2 = 0; #10;

        // 结束仿真
        $finish;
    end

    // 监视信号变化
    initial begin
        $monitor("Time=%0t | rst_n=%b | s3=%b | s0=%b | s4=%b | s1=%b | s2=%b | send_data=%h | send_enable=%b", 
                 $time, rst_n, s3, s0, s4, s1, s2, send_data, send_enable);
    end

endmodule
