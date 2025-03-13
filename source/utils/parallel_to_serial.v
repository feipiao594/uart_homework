module parallel_to_serial #(
    parameter P_WIDTH = 24,  // 并行输入数据位宽
    parameter S_WIDTH = 8    // 串行输出数据位宽
) (
    input  wire               clk,          // 时钟信号
    input  wire               rst,          // 复位信号
    input  wire               load,         // 使能加载并行数据
    input  wire  [P_WIDTH-1:0] parallel_in,  // 并行输入数据
    output reg  [S_WIDTH-1:0] serial_out,   // 串行输出数据
    output reg                valid,        // 并行数据有效信号
    output reg                busy          // 正在输出串行数据信号
);
  localparam COUNT_MAX = P_WIDTH / S_WIDTH;  // 需要多少次串行输出才能清空并行数据 
  reg [$clog2(COUNT_MAX)+1:0] counter;  // 计数器
  reg [P_WIDTH-1:0] shift_reg;  // 移位寄存器

  always @(posedge clk) begin
    if (rst) begin
      shift_reg <= 0;
      serial_out <= 0;
      valid <= 0;
      busy <= 0;
      counter <= 0;
    end else if (load && !busy) begin
      $display("[p2s input] indata: %x", parallel_in);
      shift_reg <= parallel_in;
      busy <= 1;  // 开始输出
    end else if (busy) begin
      serial_out <= shift_reg[P_WIDTH-1:P_WIDTH-S_WIDTH];
      $display("[p2s output] outdata: %x, count: %d", shift_reg[P_WIDTH-1:P_WIDTH-S_WIDTH],
               counter);
      shift_reg <= {shift_reg[P_WIDTH-S_WIDTH-1:0], {S_WIDTH{1'b0}}};
      valid <= 1;  // 数据有效
      counter <= counter + 1;
      if (counter == COUNT_MAX[$clog2(COUNT_MAX)+1:0] - 1) begin
        busy <= 0;  // 数据已经输出完毕
        counter <= 0;  // 重新计数
      end
    end

    if (!busy) begin
      valid <= 0;  // 数据未输出，无效
      serial_out <= 0;
    end
  end

endmodule
