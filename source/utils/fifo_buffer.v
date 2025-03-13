module fifo_buffer #(
    parameter DEPTH = 16,  // FIFO 深度
    parameter WIDTH = 8    // 数据位宽
) (
    input  wire             clk,       // 时钟信号
    input  wire             rst,       // 复位信号
    input  wire             wr_en,     // 写使能
    input  wire             rd_en,     // 读使能
    input  wire [WIDTH-1:0] data_in,   // 输入数据
    output reg  [WIDTH-1:0] data_out,  // 输出数据
    output wire             full,      // FIFO 满信号
    output wire             empty      // FIFO 空信号
);
  // 注意： 读写都是被动的，即读写使能信号是由外部控制的，而不是由FIFO自己控制的
  // 用满和空通知其他组件读写，所以别的组件有主动权
  localparam MAX_VALUE = DEPTH - 1;
  wire [$clog2(DEPTH)-1:0] FULL_NUMBER = MAX_VALUE[$clog2(DEPTH)-1:0];
  // **存储器**（双端口 RAM）
  reg [WIDTH-1:0] memory[0:DEPTH-1];

  // **读写指针**
  reg [$clog2(DEPTH)-1:0] write_pointer = 0, read_pointer = 0;

  // **FIFO 内部计数**
  reg [$clog2(DEPTH)-1:0] count = 0;  // 计数器

  // **状态信号**
  assign full  = (count == FULL_NUMBER);  // FIFO 是否已满
  assign empty = (count == 0);  // FIFO 是否为空
  integer i;
  // **写入读取逻辑**
  always @(posedge clk) begin
    if (rst) begin
      write_pointer <= 0;
      read_pointer <= 0;
      data_out <= 0;
      count <= 0;
      for (i = 0; i < DEPTH; i = i + 1) begin
        memory[i] <= {WIDTH{1'b0}};  // 将所有位置初始化为0
      end
    end else begin
      if (empty == 1'b0) data_out <= memory[read_pointer];  // 默认读取数据，用rd表示已收到
      if (wr_en == 1'b1 && full == 1'b0) begin
        memory[write_pointer] <= data_in;  // 写入数据
        // $display("[buffer] write data: %x", data_in);
        write_pointer <= write_pointer + 1;  // 更新写指针
        count <= count + 1;
        // $display("[buffer] count: %d, empty: %d", count, empty);
        if (empty == 1'b1) begin
          data_out <= data_in;
        end
      end
      if (rd_en == 1'b1 && empty == 1'b0) begin
        // $display("[buffer] read data: %x, count: %d", memory[read_pointer], count);
        read_pointer <= read_pointer + 1;  // 更新读指针
        if (empty == 1'b1) data_out <= memory[read_pointer+1];  // 默认读取数据，用rd表示已收到
        count <= count - 1;
      end
      if (wr_en == 1'b1 && rd_en == 1'b1 && ~(full == 1'b1 || empty == 1'b1)) begin
        count <= count;
      end
    end
  end


  // 写入与弹出只与存储进行交互，即对于写入来说满则丢弃，不满则写入，反之对弹出同理，逻辑完备

  // 注意两种特殊情况，满时读写同时，读有效，写无效
  // 空时读写同时，写有效，读无效    

  // 指针是存储的状态，对与存储无关的操作不会改变指针
endmodule
