module seg (
    count,
    scan_code,
    ascii_code,
    is_shift,
    is_ctrl,
    o_seg0,
    o_seg1,
    o_seg2,
    o_seg3,
    o_seg4,
    o_seg5,
    o_seg6,
    o_seg7
);

  input is_shift, is_ctrl;
  input [7:0] count;
  input [7:0] scan_code;
  input [7:0] ascii_code;
  output [7:0] o_seg0, o_seg1, o_seg2, o_seg3, o_seg4, o_seg5, o_seg6, o_seg7;

  parameter [7:0] hex_display[15:0] = {
    8'b10001110,
    8'b10011110,
    8'b01111010,
    8'b10011100,
    8'b00111110,
    8'b11101110,
    8'b11110110,
    8'b11111110,
    8'b11100000,
    8'b10111110,
    8'b10110110,
    8'b01100110,
    8'b11110010,
    8'b11011010,
    8'b01100000,
    8'b11111100
  };


  assign o_seg0 = ~hex_display[scan_code[3:0]];
  assign o_seg1 = ~hex_display[scan_code[7:4]];
  assign o_seg2 = 8'b11111111;
  assign o_seg3 = 8'b11111111;
  assign o_seg4 = 8'b11111111;
  assign o_seg5 = 8'b11111111;
  assign o_seg6 = 8'b11111111;
  assign o_seg7 = 8'b11111111;

endmodule

// 当前仅支持字符和数字，空格和回车等未兼容
