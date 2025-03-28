module receiver (
    input  wire       clk,
    input  wire       rst_n,
    input  wire       rxEn,      // 使能接收
    input  wire       rx,        // 串行输入数据
    output reg  [7:0] out_data,  // 8 位并行输出数据
    output reg        rxBusy,    // 接收中标志
    output reg        rxDone     // 数据接收完成标志
);

  reg [9:0] shift_reg;  // 移位寄存器（包括起始位 + 8位数据 + 停止位）
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
    if (!rst_n || !rxEn) begin
      shift_reg <= 10'b0;
      rxBusy   <= 1'b0;
      rxDone   <= 1'b0;
      bit_cnt  <= 0;
      out_data <= 8'b0;
      state    <= IDLE;
    end else begin
      case (state)
        // **等待起始位**
        IDLE: begin
          rxDone  <= 1'b0;
          rxBusy  <= 1'b0;
          bit_cnt <= 0;
          state   <= START;
        end

        // **检测起始位是否有效**
        START: begin
          if (rx == 1'b0) begin  // 确认起始位仍然为 0
            if (baud_tick) begin
              state <= DATA;  // 在波特率周期到来后，开始接收数据
            end
          end
        end

        // **接收 8 位数据**
        DATA: begin
          rxBusy <= 1'b1;  // 开始接收
          if (baud_tick) begin
            shift_reg <= {
              shift_reg[8:0], rx
            };  // 左移并存入新位 最终数据格式为起始+8数据+终止
            bit_cnt <= bit_cnt + 1;
            if (bit_cnt == 7) state <= STOP;  // 数据接收完成，进入停止位检测
          end
        end

        // **验证停止位并输出数据**
        STOP:
        if (baud_tick) begin
          if (rx == 1'b1) begin  // 停止位必须是 1
            out_data <= shift_reg[7:0];  // 提取数据位
            $display("[uart receiver] STOP, %x", shift_reg[7:0]);
          end
          rxDone <= 1'b1;  // 接收完成信号
          rxBusy <= 1'b0;  // 释放忙信号
          state  <= IDLE;  // 复位回到等待状态
        end
      endcase
    end
  end

endmodule
