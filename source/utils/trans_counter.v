module trans_counter #(
    parameter WIDTH     = 8,   // 计数器位宽
    parameter MAX_VALUE = 255  // 计数器最大值
) (
    input  wire clk,         // 时钟信号
    input  wire rst,         // 复位信号
    input  wire inc,         // 加 1 触发
    input  wire dec,         // 减 1 触发
    output reg  max_reached  // 达到最大值标志
);

  reg [WIDTH-1:0] count;  // 计数值
  wire [WIDTH-1:0] MAX_VALUE_W = MAX_VALUE;

  always @(posedge clk) begin
    if (rst) begin
      count <= 0;
      max_reached <= 0;
    end else begin
      // **优先处理加法**
      if (inc && count < MAX_VALUE_W) begin
        count <= count + 1;
      end  // **如果没有加法，处理减法**
      else if (dec && count > 0) begin
        count <= count - 1;
      end

      // **更新 max_reached 标志**
      if (count == MAX_VALUE_W) begin
        max_reached <= 1;
      end else begin
        max_reached <= 0;
      end
    end
  end

endmodule
