`timescale 1ns/1ps

module tb_sender;
    reg clk;
    reg txEn;
    reg txStart;
    reg [7:0] in_data;
    wire tx;
    wire txBusy;
    wire txDone;

    // ??????? UART ????
    sender uut (
        .clk(clk),
        .txEn(txEn),
        .txStart(txStart),
        .in_data(in_data),
        .tx(tx),
        .txBusy(txBusy),
        .txDone(txDone)
    );

    // 50MHz ???? = 20ns
    always #10 clk = ~clk;

    initial begin
        // ?????
        clk = 0;
        txEn = 0;
        txStart = 0;
        in_data = 8'h00;

        // ????
        #50;
        txEn = 1;  // ??????

        // ??????? 8'hA5
        #50;
        in_data = 8'hA5;
        txStart = 1;
        #20;
        txStart = 0; // ?? txStart???????

        // ??????
        wait (txDone);
        #50;

        // ??????? 8'h3C
        in_data = 8'h3C;
        txStart = 1;
        #20;
        txStart = 0;

        // ??????
        wait (txDone);
        #100;

        // ????
        $stop;
    end

    // ?? UART ????
    initial begin
        $monitor("Time = %d, tx = %b, txBusy = %b, txDone = %b", $time, tx, txBusy, txDone);
    end
endmodule

