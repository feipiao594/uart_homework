`timescale 1ns / 1ps

module baudrate_generator_tb;
  reg         clk;  // 系统时钟
  reg         rst_n;  // 复位信号
  reg  [31:0] clk_freq;  // 时钟频率（单位：Hz）
  wire        baud_tick;  // 波特率时钟信号

  // 实例化波特率发生器
  baudrate_generator uut (
      .clk(clk),
      .rst_n(rst_n),
      .clk_freq(clk_freq),
      .baud_tick(baud_tick)
  );

  // 50MHz 时钟生成
  always #10 clk = ~clk;  // 时钟周期 20ns，频率 50MHz

  initial begin
    // 初始化
    clk = 0;
    rst_n = 0;
    clk_freq = 50000000;  // 设置时钟频率为 50MHz
    #20 rst_n = 1;  // 释放复位信号

    // 仿真 200000ns，观察 `baud_tick` 输出
    #200000;

    // 结束仿真
    $stop;
  end

  // 监视信号
  initial begin
    $monitor("Time = %0t, clk_freq = %0d, baud_tick = %b", $time, clk_freq, baud_tick);
  end
endmodule
