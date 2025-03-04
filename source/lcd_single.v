module lcd_single (
    input reg [3:0] single_byte,
    input reg enable,
    output reg [7:0] ports
);

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

    assign ports = enable == 1'b1 ? ~hex_display[single_byte] : 8'b11111111;
    
endmodule