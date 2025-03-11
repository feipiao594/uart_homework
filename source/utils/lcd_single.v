module lcd_single (
    input wire [3:0] single_byte,
    input wire enable,
    output wire [7:0] ports
);

  reg [7:0] hex_display[15:0];

  initial begin
    $readmemh("./resource/mem.hex", hex_display, 0, 15);
  end

  assign ports = (enable == 1'b1 ? ~hex_display[single_byte] : 8'b11111111);

endmodule
