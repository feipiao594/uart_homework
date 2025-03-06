module fifo_buffer #(
    parameter DEPTH = 16,  // FIFO 深度
    parameter WIDTH = 8    // 数据位宽
)(
    input wire clk,        // 时钟信号
    input wire rst,        // 复位信号
    input wire wr_en,      // 写使能
    input wire rd_en,      // 读使能
    input wire [WIDTH-1:0] data_in,  // 输入数据
    output reg [WIDTH-1:0] data_out, // 输出数据
    output wire full,      // FIFO 满信号
    output wire empty      // FIFO 空信号
);
    // 注意： 读写都是被动的，即读写使能信号是由外部控制的，而不是由FIFO自己控制的
    // 用满和空通知其他组件读写，所以别的组件有主动权

    // **存储器**（双端口 RAM）
    reg [WIDTH-1:0] memory [0:DEPTH-1];

    // **读写指针**
    reg [$clog2(DEPTH)-1:0] write_pointer = 0, read_pointer = 0;

    // **FIFO 内部计数**
    reg [$clog2(DEPTH+1):0] count = 0;  // 计数器

    // **状态信号**
    assign full = (count == DEPTH);  // FIFO 是否已满
    assign empty = (count == 0);     // FIFO 是否为空

    // **写入读取逻辑**
    always @(posedge clk) begin
        if (rst) begin
            write_pointer <= 0;
            read_pointer <= 0;
            data_out <= 0;
        end
        else if (rd_en && wr_en && (full || empty)) begin
            data_out <= data_in;
        end
        else if (wr_en && !full) begin
            memory[write_pointer] <= data_in;  // 写入数据
            write_pointer <= write_pointer + 1;  // 更新写指针
        end
        else if (rd_en && !empty) begin
            data_out <= memory[read_pointer];  // 读取数据
            read_pointer <= read_pointer + 1;  // 更新读指针
        end
    end

    // 在空和满的情况下，数据其实不会经过存储，空的话写入的数据会直接输出，满的话不能写入数据
    // 只此两种情况写入与弹出与存储无关，其他情况写入弹出都会与存储交互
    // 其他情况写入与弹出只与存储进行交互，即对于写入来说满则丢弃，不满则写入，反之对弹出同理，逻辑完备

    // 指针是存储的状态，对与存储无关的操作不会改变指针

    // **FIFO 计数管理**，计数器在仅写入和仅读取时更新
    always @(posedge clk) begin
        if (rst) begin
            count <= 0;
        end
        else begin
            case ({wr_en, rd_en})
                2'b10: if (!full) count <= count + 1;
                2'b01: if (!empty) count <= count - 1;
                default: count <= count;
            endcase
        end
    end
endmodule
