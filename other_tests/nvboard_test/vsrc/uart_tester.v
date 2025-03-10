module uart_tester(
    clk,
    btn,
    o_seg0,
    o_seg1,
    o_seg2,
    o_seg3,
    o_seg4,
    o_seg5,
    o_seg6,
    o_seg7,
    feipiao_0_sw
);
  input [4:0] btn;
  input clk;
  output [7:0] o_seg0, o_seg1, o_seg2, o_seg3, o_seg4, o_seg5, o_seg6, o_seg7;
  wire [7:0] input_data;
  wire [15:0] ports;
  wire start;
  input wire feipiao_0_sw;

  wire my_communication_uart_tx;
  wire my_communication_uart_rx;
  wire my_communication_uart_seg;

  communication_uart my_communication_uart (
      .btn(btn),
      .switch_sw(feipiao_0_sw),
      .clk(clk),
      .rst_n(1'b1),
      .seg(ports),
      .tx(my_communication_uart_rx),
      /* verilator lint_off PINCONNECTEMPTY */
      .txDone(),
      /* verilator lint_off PINCONNECTEMPTY */
      .txBusy(),
      .rx(my_communication_uart_tx),
      /* verilator lint_off PINCONNECTEMPTY */
      .rxDone(),
      /* verilator lint_off PINCONNECTEMPTY */
      .rxBusy()
  );


  assign o_seg0 = ports[7:0];
  assign o_seg1 = ports[15:8];
  assign o_seg2 = 8'b11111111;
  assign o_seg3 = 8'b11111111;
  assign o_seg4 = 8'b11111111;
  assign o_seg5 = 8'b11111111;
  assign o_seg6 = 8'b11111111;
  assign o_seg7 = 8'b11111111;
    

endmodule