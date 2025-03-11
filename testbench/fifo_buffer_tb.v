`timescale 1ns / 1ps

module fifo_dualport_tb;

  // 参数定义
  parameter DEPTH = 16;  // FIFO 深度
  parameter WIDTH = 8;  // 数据位宽

  // 信号定义
  reg clk;
  reg rst;
  reg wr_en, rd_en;
  reg  [WIDTH-1:0] data_in;
  wire [WIDTH-1:0] data_out;
  wire full, empty;

  // 实例化 FIFO DUT (Device Under Test)
  fifo_dualport #(
      .DEPTH(DEPTH),
      .WIDTH(WIDTH)
  ) uut (
      .clk(clk),
      .rst(rst),
      .wr_en(wr_en),
      .rd_en(rd_en),
      .data_in(data_in),
      .data_out(data_out),
      .full(full),
      .empty(empty)
  );

  // **时钟信号生成**
  always #5 clk = ~clk;  // 10ns 1个时钟周期

  initial begin
    // **初始化信号**
    clk = 0;
    rst = 1;
    wr_en = 0;
    rd_en = 0;
    data_in = 0;

    // **复位 FIFO**
    #20 rst = 0;  // 释放复位信号

    // **写入 5 个数据**
    #10 wr_en = 1;
    data_in = 8'h11;
    #10 data_in = 8'h22;
    #10 data_in = 8'h33;
    #10 data_in = 8'h44;
    #10 data_in = 8'h55;
    #10 wr_en = 0;  // 停止写入

    // **读取 3 个数据**
    #10 rd_en = 1;
    #10;
    #10;
    #10 rd_en = 0;  // 停止读取

    // **写入更多数据**
    #10 wr_en = 1;
    data_in = 8'h66;
    #10 data_in = 8'h77;
    #10 data_in = 8'h88;
    #10 data_in = 8'h99;
    #10 data_in = 8'hAA;
    #10 wr_en = 0;

    // **继续读取数据**
    #10 rd_en = 1;
    #100 rd_en = 0;  // 读取到 FIFO 为空

    // **测试 FIFO 满的情况**
    #10 wr_en = 1;
    for (int i = 0; i < DEPTH; i = i + 1) begin
      #10 data_in = i;
    end
    #10 wr_en = 0;

    // **FIFO 满后继续写入，应该不会存储数据**
    #10 wr_en = 1;
    data_in = 8'hFF;
    #10 wr_en = 0;

    // **读取所有数据**
    #10 rd_en = 1;
    #200 rd_en = 0;

    // **FIFO 变空后继续读取，应该不会输出新的数据**
    #10 rd_en = 1;
    #50 rd_en = 0;

    #20 $finish;  // 结束仿真
  end

  // **监视信号**
  initial begin
    $dumpfile("fifo_dualport_tb.vcd");  // 生成波形文件
    $dumpvars(0, fifo_dualport_tb);  // 监视所有信号
    $monitor("Time: %t | wr_en: %b | rd_en: %b | data_in: %h | data_out: %h | full: %b | empty: %b",
             $time, wr_en, rd_en, data_in, data_out, full, empty);
  end

endmodule
