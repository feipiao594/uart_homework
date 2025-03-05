module top(
    input wire clk,        // 时钟
    input wire rst,        // 复位
    input wire wr_en,      // 写使能
    input wire rd_en,      // 读使能
    input wire [7:0] data_in,  // 写入数据
    output wire [7:0] data_out, // 读取数据
    output wire full,      // FIFO 是否满
    output wire empty      // FIFO 是否空
    );

    fifo_buffer #(.DEPTH(16), .WIDTH(8)) m_fifo_buffer(
        .clk(clk),
        .rst(rst),
        .wr_en(wr_en),
        .rd_en(rd_en),
        .data_in(data_in),
        .data_out(data_out),
        .full(full),
        .empty(empty)
    );

endmodule
