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
    o_seg7
);
  input [4:0] btn;
  input clk;
  output [7:0] o_seg0, o_seg1, o_seg2, o_seg3, o_seg4, o_seg5, o_seg6, o_seg7;
  wire [7:0] input_data;
  wire [15:0] ports;
  wire start;

  sender_controller my_sender_controller (
      .clk(clk),
      .rst_n(1'b1),
      .s3(btn[3]),
      .s0(btn[0]),
      .s4(btn[4]),
      .s1(btn[1]),
      .s2(btn[2]),
      .send_data(input_data[7:0]),
      .send_start(start)
  );

  lcd_double my_lcd_double (
      .data(input_data[7:0]),
      .enable(1'b1),
      .ports(ports)
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