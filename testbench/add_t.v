`timescale 1ns / 1ps

module add_t;

    // ???????????
    reg a, b;
    wire c;

    // ????????DUT: Device Under Test?
    add uut (
        .a(a),
        .b(b),
        .c(c)
    );

    // ????
    initial begin
        // ??????
        $monitor("Time = %0t | a = %b | b = %b | c = %b", $time, a, b, c);

        // ?????
        a = 0; b = 0; #10;
        a = 0; b = 1; #10;
        a = 1; b = 0; #10;
        a = 1; b = 1; #10;

        // ????
        $finish;
    end

endmodule