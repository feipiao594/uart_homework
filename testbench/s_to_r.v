`timescale 1ns / 1ps

module s_to_r;
  reg clk;
  reg rst_n;
  reg txEn;
  reg rxEn;
  reg txStart;
  reg [7:0] in_data;
  wire tx;
  wire txBusy;
  wire txDone;
  wire [7:0] out_data;
  wire rxBusy;
  wire rxDone;
  wire right;
  wire rx;  // rx 是 receiver 模块的输入，它接收来自 sender 的数据

  // 实例化 sender 模块
  sender sender_inst (
      .clk(clk),
      .rst_n(rst_n),
      .txEn(txEn),
      .txStart(txStart),
      .in_data(in_data),
      .tx(tx),  // sender 的输出 tx
      .txBusy(txBusy),
      .txDone(txDone)
  );

  // 实例化 receiver 模块
  receiver receiver_inst (
      .clk(clk),
      .rst_n(rst_n),
      .rxEn(rxEn),
      .rx(tx),  // receiver 接收来自 sender 的 tx 数据
      .out_data(out_data),
      .rxBusy(rxBusy),
      .rxDone(rxDone),
      .right(right)
  );

  // 50MHz 时钟
  always #10 clk = ~clk;

  initial begin
    // 初始化信号
    clk = 0;
    rst_n = 0;
    txEn = 0;
    rxEn = 0;
    txStart = 0;
    in_data = 8'b0;

    // 释放复位信号
    #50 rst_n = 1;

    // 使能发送器和接收器
    #20 txEn = 1;
    rxEn = 1;

    // 发送三个数据帧
    send_data(8'hA5);  // 发送第一个数据帧: 0xA5
    #100000;  // 等待一段时间

    send_data(8'h3C);  // 发送第二个数据帧: 0x3C
    #100000;

    send_data(8'h7F);  // 发送第三个数据帧: 0x7F
    #100000;

    // 结束仿真
    $stop;
  end

  // 模拟发送数据
  task send_data(input [7:0] data);
    begin
      in_data = data;
      txStart = 1;  // 激活 txStart 信号
      #20 txStart = 0;  // 产生一个短脉冲
      #1000;  // 等待数据发送完成
    end
  endtask

endmodule
