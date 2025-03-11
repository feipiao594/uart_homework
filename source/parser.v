module parser (
    input wire clk,
    input wire rst_n,  // 复位信号
    input wire En,
    input wire [7:0] indata,
    output reg [7:0] outdata,
    output reg pBusy,
    output reg pDone,
    output reg data_valid
);

  // 状态机状态定义
  parameter IDLE = 3'b000;
  parameter HEADER = 3'b001;
  parameter LENGTH = 3'b010;
  parameter CMD = 3'b011;
  parameter DATA = 3'b100;
  parameter CHECK = 3'b101;
  parameter TAIL = 3'b110;

  reg [2:0] state;
  reg [7:0] checksum;  // 计算累加和
  reg [3:0] data_cnt;  // 记录接收数据的字节数
  reg [63:0] data_buf;

  reg busy;
  reg ptsEn;
  parallel_to_serial #(
      .P_WIDTH(64),  // 并行输入数据位宽
      .S_WIDTH(8)    // 串行输出数据位宽
  ) PTS (
      .clk        (clk),         // 时钟信号
      .rst        (~rst_n),      // 复位信号
      .load       (ptsEn),       // 使能加载并行数据
      .parallel_in(data_buf),    // 并行输入数据
      .serial_out (outdata),     // 串行输出数据
      .valid      (data_valid),  // 并行数据有效信号
      .busy       (busy)         // 正在输出串行数据信号
  );

  always @(posedge clk) begin
    if (!rst_n) begin
      state    <= IDLE;
      pBusy    <= 1'b0;
      pDone    <= 1'b0;
      checksum <= 8'b0;
      data_cnt <= 4'b0;
      data_buf <= 64'b0;
      ptsEn <= 1'b0;
    end else begin  /* verilator lint_off CASEINCOMPLETE */
      case (state)
        IDLE: begin
          pBusy    <= 1'b0;
          pDone    <= 1'b0;
          checksum <= 8'b0;
          data_cnt <= 4'b0;
          ptsEn <= 1'b0;
          data_buf <= 64'b0;
          state <= HEADER;
        end

        HEADER:
        if (En) begin
          // $display("[parser]: state: `HEADER`, indata: %x", indata);
          if (indata == 8'h52) begin
            pBusy <= 1'b1;
            checksum <= indata;
            state <= LENGTH;
          end
        end

        LENGTH:
        if (En) begin
          // $display("[parser]: state: `LENGTH`, indata: %x", indata);
          if (indata == 8'h0D) begin
            checksum <= checksum + indata;
            state <= CMD;
          end
        end

        CMD:
        if (En) begin
          // $display("[parser]: state: `CMD`, indata: %x", indata);
          if (indata == 8'h01) begin
            checksum <= checksum + indata;
            state <= DATA;
          end
        end

        DATA:
        if (En) begin
          // $display("[parser]: state: `DATA`, indata: %x", indata);
          data_buf[(7-data_cnt)*8+:8] <= indata;
          checksum <= checksum + indata;
          if (data_cnt == 7) begin
            state <= CHECK;  // 8 个字节数据接收完成
          end
          data_cnt <= data_cnt + 1;
        end

        CHECK:
        if (En) begin
          // $display("[parser]: state: `CHECK`, indata: %x", indata);
          checksum <= checksum + indata;
          state <= TAIL;
        end

        TAIL:
        if (En) begin
          // $display("[parser]: state: `TAIL`, indata: %x", indata);
          if (indata != 8'h9A) begin  // 确保尾部正确
            // $display("[parser]: tail error");
            state <= IDLE;
            pBusy <= 1'b0;
            pDone <= 1'b0;
          end else
          // $display("[parser]: tail right");
          if (checksum + indata == 255) begin
            $display("[parser]: data accepted: %x", data_buf);
            ptsEn <= 1'b1;
          end else begin
            // $display("[parser]: data not accepted, checksum calculate: %b", checksum + indata);
          end
          pBusy <= 1'b0;
          pDone <= 1'b1;
          state <= IDLE;
        end
      endcase
    end
  end

endmodule
