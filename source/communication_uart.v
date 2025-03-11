module communication_uart (
    input  wire [ 4:0] btn,
    input  wire        switch_sw,
    input  wire        clk,        // 时钟信号
    input  wire        rst_n,      // 复位信号（低有效）
    output wire [15:0] seg,
    output wire        tx,
    output wire        txDone,
    output wire        txBusy,
    output wire        rx,
    output wire        rxDone,
    output wire        rxBusy
);

  wire [7:0] preview_data;
  wire [7:0] receive_data;
  wire sc_data_valid;
  wire [7:0] sc_send_data;
  wire [7:0] sender_data;
  wire sf_data_ready;
  wire sf_empty;
  wire [7:0] receiver_data;
  wire parser_data_valid;
  wire rf_empty;
  wire [7:0] parser_in_data;
  wire [7:0] parser_out_data;
  wire pf_empty;
  wire parser_busy;
  reg btn_0_prev;

  sender_controller m_sender_controller (
      .clk         (clk),            // 时钟信号
      .rst_n       (rst_n),          // 复位信号（低有效）
      .s3          (btn[3]),         // 选择数据存储位置
      .s0          (btn[0]),
      .s1          (btn[1]),         // 数据调整键
      .s4          (btn[4]),
      .s2          (btn[2]),         // 确认发送
      .send_data   (sc_send_data),   // 发送数据
      .preview_data(preview_data),   // 预览数据
      .data_valid  (sc_data_valid),  // 数据有效信号
      /* verilator lint_off PINCONNECTEMPTY */
      .busy        (),
      .btn_en      (~switch_sw)
  );

  fifo_buffer sender_buffer (
      .clk(clk),
      .rst(~rst_n),
      .wr_en(sc_data_valid),
      .rd_en(~sf_empty && ~txBusy),
      .data_in(sc_send_data),
      .data_out(sender_data),
      /* verilator lint_off PINCONNECTEMPTY */
      .full(),
      .empty(sf_empty)
  );

  sender m_sender (
      .clk(clk),
      .rst_n(rst_n),
      .txEn(1'b1),
      .txStart(~sf_empty),
      .in_data(sender_data),
      .tx(tx),
      .txBusy(txBusy),
      .txDone(txDone)
  );

  receiver m_receiver (
      .clk(clk),
      .rst_n(rst_n),
      .rxEn(1'b1),
      .rx(rx),
      .out_data(receiver_data),
      .rxBusy(rxBusy),
      .rxDone(rxDone)
  );

  fifo_buffer receiver_buffer (
      .clk(clk),
      .rst(~rst_n),
      .wr_en(rxDone),
      .rd_en(~rf_empty || ~parser_busy),
      .data_in(receiver_data),
      .data_out(parser_in_data),
      /* verilator lint_off PINCONNECTEMPTY */
      .full(),
      .empty(rf_empty)
  );

  parser m_parser (
      .clk(clk),
      .rst_n(rst_n),
      .En(~rf_empty),
      .indata(parser_in_data),
      .outdata(parser_out_data),
      .pBusy(parser_busy),
      .data_valid(parser_data_valid),
      /* verilator lint_off PINCONNECTEMPTY */
      .pDone()
  );

  always @(posedge clk) begin
    if (!rst_n) begin
      btn_0_prev <= 1'b0;
    end else begin
      btn_0_prev <= btn[0];
    end
    if (btn[0] && !btn_0_prev && ~pf_empty) $display("[communication uart] receive data: %x", receive_data);
    if (parser_data_valid) $display("[communication uart] parser data: %x", parser_out_data);
  end

  fifo_buffer parser_buffer (
      .clk(clk),
      .rst(~rst_n),
      .wr_en(parser_data_valid),
      .rd_en(btn[0] && !btn_0_prev && switch_sw && !pf_empty),
      .data_in(parser_out_data),
      .data_out(receive_data),
      /* verilator lint_off PINCONNECTEMPTY */
      .full(),
      .empty(pf_empty)
  );

  lcd_double m_lcd_double (
      .data(switch_sw ? (pf_empty ? 0 : receive_data) : preview_data),  // 数据
      .enable(1'b1),  // 使能
      .ports(seg)  // 输出端口
  );


endmodule
