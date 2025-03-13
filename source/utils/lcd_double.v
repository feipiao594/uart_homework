module lcd_double (
    input wire [7:0] data,
    input wire enable,
    output wire [15:0] ports
);

  lcd_single high_lcd_single (
      .single_byte(data[7:4]),
      .enable(enable),
      .ports(ports[15:8])
  );

  lcd_single low_lcd_single (
      .single_byte(data[3:0]),
      .enable(enable),
      .ports(ports[7:0])
  );
endmodule
