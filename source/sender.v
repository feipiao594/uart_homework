module sender(
    input  wire       clk,        
    input  wire       txEn,       
    input  wire       txStart,     
    input  wire [7:0] in_data,    
    output reg        tx,         
    output reg        txBusy,     
    output reg        txDone      
);

    reg [9:0] shift_reg;  
    reg [3:0] bit_cnt;    
    reg sending;          

    parameter IDLE  = 2'b00;
    parameter START = 2'b01;
    parameter DATA  = 2'b10;
    parameter STOP  = 2'b11;

    reg [1:0] state;

    always @(posedge clk) begin
        if (!txEn) begin  
            state    <= IDLE;
            tx       <= 1'b1;  
            txBusy   <= 1'b0;  
            txDone   <= 1'b0;  
            bit_cnt  <= 0;     
            sending  <= 0;     
        end else begin
            case (state)
                IDLE: begin
                    txBusy <= 1'b0; 
                    txDone <= 1'b0; 
                    tx     <= 1'b1; 

                    if (txStart) begin  
                        shift_reg <= {1'b1, in_data, 1'b0}; 
                        bit_cnt   <= 0;   
                        txBusy    <= 1'b1; 
                        sending   <= 1'b1; 
                        state     <= START; 
                    end
                end

                START: begin
                    tx       <= shift_reg[0]; 
                    shift_reg <= {1'b0, shift_reg[9:1]}; 
                    state    <= DATA; 
                end

                DATA: begin
                    tx       <= shift_reg[0]; 
                    shift_reg <= {1'b0, shift_reg[9:1]}; 
                    bit_cnt  <= bit_cnt + 1;
                    if (bit_cnt == 7) state <= STOP; 
                end

                STOP: begin
                    tx       <= 1'b1; 
   		    txDone   <= 1'b1; 
                    state    <= IDLE; 
                    sending  <= 1'b0; 
                end
            endcase
        end
    end
    
endmodule
