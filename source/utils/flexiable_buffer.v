module flexiable_buffer #(
    parameter IN_WIDTH = 8,  // 输入数据位宽
    parameter OUT_WIDTH = 16,   // 输出数据位宽
    parameter FIFO_DEPTH = 16 // 大的一端 FIFO 深度
)(
    input wire clk,
    input wire rst,        // 时钟 & 复位
    input wire wr_en,      // 写使能
    input wire rd_en,      // 读使能
    input wire [IN_WIDTH-1:0] data_in, // 输入数据
    output wire [OUT_WIDTH-1:0] data_out, // 输出数据
    output wire full,      // 不可写信号
    output wire empty      // 不可读信号
);

    // **如果 IN_WIDTH > OUT_WIDTH P2S（高位转低位）**
    generate
        if (IN_WIDTH > OUT_WIDTH) begin: P2S_MODE

            wire [OUT_WIDTH-1:0] p2s_serial_out;
            wire [IN_WIDTH-1:0] p2s_parallel_in;
            wire p2s_valid;
            wire p2s_busy;
            wire fifo_empty;
            wire max_reached;
            
            wire load_signal;
            assign load_signal = !max_reached && !p2s_busy && !fifo_empty;

            trans_counter  #(
                .WIDTH(IN_WIDTH),
                .MAX_VALUE(FIFO_DEPTH-1)
            ) p2s_trans_counter (
                .clk(clk),
                .rst(rst),
                .inc(load_signal),
                .dec(rd_en),
                .max_reached(max_reached)
            );

            // **输入 FIFO**
            fifo_buffer #(.DEPTH(FIFO_DEPTH), .WIDTH(IN_WIDTH)) HighFIFO (
                .clk(clk),
                .rst(rst),
                .wr_en(wr_en),
                .rd_en(load_signal),
                .data_in(data_in),
                .data_out(p2s_parallel_in),
                .full(full),
                .empty(fifo_empty)
            );

            // **并行转串行**
            parallel_to_serial #(.P_WIDTH(IN_WIDTH), .S_WIDTH(OUT_WIDTH)) P2S (
                .clk(clk),
                .rst(rst),
                .load(rd_en),
                .parallel_in(p2s_parallel_in),
                .serial_out(p2s_serial_out),
                .valid(p2s_valid),
                .busy(p2s_busy)
            );

            // **输出 FIFO**
            fifo_buffer #(.DEPTH(FIFO_DEPTH*IN_WIDTH/OUT_WIDTH), .WIDTH(OUT_WIDTH)) LowFIFO (
                .clk(clk),
                .rst(rst),
                .wr_en(p2s_valid),
                .rd_en(rd_en),
                .data_in(p2s_serial_out),
                .data_out(data_out),
                /* verilator lint_off PINCONNECTEMPTY */
                .full(),
                .empty(empty)
            );
        end 
        // **如果 IN_WIDTH < OUT_WIDTH S2P（低位转高位）**
        else if (IN_WIDTH < OUT_WIDTH) begin: S2P_MODE
            wire [OUT_WIDTH-1:0] s2p_parallel_out;
            wire [IN_WIDTH-1:0] s2p_serial_in;
            wire s2p_valid;
            wire fifo_empty;
            wire max_reached;
            
            wire load_signal;
            assign load_signal = !max_reached && !fifo_empty;

            trans_counter  #(
                .WIDTH(IN_WIDTH),
                .MAX_VALUE(FIFO_DEPTH*IN_WIDTH/OUT_WIDTH-1)
            ) p2s_trans_counter (
                .clk(clk),
                .rst(rst),
                .inc(load_signal),
                .dec(rd_en),
                .max_reached(max_reached)
            );

            // **输入 FIFO**
            fifo_buffer #(.DEPTH(FIFO_DEPTH*OUT_WIDTH/IN_WIDTH), .WIDTH(IN_WIDTH)) LowFIFO (
                .clk(clk),
                .rst(rst),
                .wr_en(wr_en),
                .rd_en(load_signal),
                .data_in(data_in),
                .data_out(s2p_serial_in),
                .full(full),
                .empty(fifo_empty)
            );

            // **串行转并行**
            serial_to_parallel #(.S_WIDTH(IN_WIDTH), .P_WIDTH(OUT_WIDTH)) S2P (
                .clk(clk),
                .rst(rst),
                .load(load_signal),
                .serial_in(s2p_serial_in),
                .parallel_out(s2p_parallel_out),
                .valid(s2p_valid)
            );

            // **输出 FIFO**
            fifo_buffer #(.DEPTH(FIFO_DEPTH), .WIDTH(OUT_WIDTH)) HighFIFO (
                .clk(clk),
                .rst(rst),
                .wr_en(s2p_valid),
                .rd_en(rd_en),
                .data_in(s2p_parallel_out),
                .data_out(data_out),
                /* verilator lint_off PINCONNECTEMPTY */
                .full(),
                .empty(empty)
            );
        end 
        // **如果 IN_WIDTH == OUT_WIDTH，直接用 FIFO 传输**
        else begin: DIRECT_MODE
            fifo_buffer #(.DEPTH(FIFO_DEPTH), .WIDTH(IN_WIDTH)) DirectFIFO (
                .clk(clk),
                .rst(rst),
                .wr_en(wr_en),
                .rd_en(rd_en),
                .data_in(data_in),
                .data_out(data_out),
                .full(full),
                .empty(empty)
            );
        end
    endgenerate

endmodule
