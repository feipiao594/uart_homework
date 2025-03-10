module sender (
    input  wire       clk,
    input  wire       rst_n,    // 复位信号
    input  wire       txEn,
    input  wire       txStart,
    input  wire [7:0] in_data,
    output reg        tx,
    output reg        txBusy,
    output reg        txDone
);

  reg [9:0] shift_reg;
  reg [3:0] bit_cnt;

  parameter IDLE = 2'b00;
  parameter START = 2'b01;
  parameter DATA = 2'b10;
  parameter STOP = 2'b11;

  reg [1:0] state;

  // **添加波特率发生器**
  wire baud_tick;
  baudrate_generator baud_gen (
      .clk(clk),
      .rst_n(rst_n),
      .clk_freq(32'd50000000),  // 50MHz 时钟
      .baud_tick(baud_tick)
  );

  always @(posedge clk) begin
    if (!rst_n || !txEn) begin
      state     <= IDLE;
      tx        <= 1'b1;
      txBusy    <= 1'b0;
      txDone    <= 1'b0;
      shift_reg <= 10'b0;
      bit_cnt   <= 0;
    end else begin  // **仅在 baud_tick 有效时执行发送**
      case (state)
        IDLE: begin
          txBusy <= 1'b0;
          txDone <= 1'b0;
          tx     <= 1'b1;

          if (txStart) begin
            shift_reg <= {1'b0, in_data, 1'b1};  // **起始位(0) + 数据(8) + 停止位(1)**
            // $display("[uart sender] IDLE, get data: %x", in_data);
            bit_cnt   <= 0;
            txBusy    <= 1'b1;
            state     <= START;
          end
        end

        START: begin
          if (baud_tick) begin
            // $display("[uart sender] START, send: ", shift_reg[9]);
            tx        <= shift_reg[9];
            shift_reg <= {shift_reg[8:0], 1'b0};
            state     <= DATA;
          end
        end

        DATA: begin
          if (baud_tick) begin
            // $display("[uart sender] DATA, send: ", shift_reg[9]);
            tx        <= shift_reg[9];
            shift_reg <= {shift_reg[8:0], 1'b0};
            bit_cnt   <= bit_cnt + 1;
            if (bit_cnt == 7) state <= STOP;
          end
        end

        STOP: begin
          if (baud_tick) begin
            // $display("[uart sender] STOP, send: ", shift_reg[9]);
            tx     <= 1'b1;
            txBusy <= 1'b0;
            txDone <= 1'b1;
            state  <= IDLE;
          end
        end
      endcase
    end
  end

endmodule
