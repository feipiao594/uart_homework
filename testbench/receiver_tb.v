`timescale 1ns/1ps

module receiver_tb;
    reg clk;
    reg rst_n;
    reg rxEn;
    reg rx;  // 串行接收数据
    wire [7:0] out_data;  // 并行输出数据
    wire rxBusy;  // 接收中标志
    wire rxDone;  // 数据接收完成标志
    wire right;

    // 实例化 receiver
    receiver uut (
        .clk(clk),
        .rst_n(rst_n),
        .rxEn(rxEn),
        .rx(rx),
        .out_data(out_data),
        .rxBusy(rxBusy),
        .rxDone(rxDone),
        .right(right)
    );

    // 50MHz 时钟（20ns周期）
    always #10 clk = ~clk;

    initial begin
        // 初始化信号
        clk = 0;
        rst_n = 0;
        rxEn = 0;
        rx = 1;  // 默认空闲状态（高电平）

        // 释放复位
        #50 rst_n = 1;
        #20 rxEn = 1;  // 使能接收

        // 模拟数据接收过程（起始位0 -> 数据 -> 停止位1）
        #100 rx = 0;  // 起始位
        #8680 rx = 1;  // 数据位 1
        #8680 rx = 0;  // 数据位 0
        #8680 rx = 1;  // 数据位 1
        #8680 rx = 0;  // 数据位 0
        #8680 rx = 1;  // 数据位 1
        #8680 rx = 1;  // 数据位 1
        #8680 rx = 0;  // 数据位 0
        #8680 rx = 1;  // 数据位 1
        #8680 rx = 1;  // 停止位 1

        // 等待接收完成
        #10000;

        // 结束仿真
        $stop;
    end

endmodule
