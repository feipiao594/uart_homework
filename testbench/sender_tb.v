`timescale 1ns / 1ps

module sender_tb;
  reg clk;
  reg rst_n;
  reg txEn;
  reg txStart;
  reg [7:0] in_data;
  wire tx;
  wire txBusy;
  wire txDone;

  // 生成 50MHz 时钟
  always #10 clk = ~clk;

  // 实例化 sender
  sender uut (
      .clk(clk),
      .rst_n(rst_n),
      .txEn(txEn),
      .txStart(txStart),
      .in_data(in_data),
      .tx(tx),
      .txBusy(txBusy),
      .txDone(txDone)
  );

  initial begin
    // 初始化信号
    clk = 0;
    rst_n = 0;
    txEn = 0;
    txStart = 0;
    in_data = 8'h96;  // 发送 8'h96 (0100101101)

    // 释放复位
    #50 rst_n = 1;
    #20 txEn = 1;

    // 触发 txStart
    #100 txStart = 1;
    #20 txStart = 0;

    // 等待一段时间，确保数据发送完成
    #100000;

    // 结束仿真
    $stop;
  end

endmodule
