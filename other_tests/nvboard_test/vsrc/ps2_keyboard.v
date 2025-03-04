module ps2_keyboard (
    clk,
    resetn,
    ps2_clk,
    ps2_data,
    o_seg0,
    o_seg1,
    o_seg2,
    o_seg3,
    o_seg4,
    o_seg5,
    o_seg6,
    o_seg7
);
  input clk, resetn, ps2_clk, ps2_data;
  output [7:0] o_seg0, o_seg1, o_seg2, o_seg3, o_seg4, o_seg5, o_seg6, o_seg7;

  reg [7:0] push_count;
  reg [7:0] scan_code, ascii_code;
  reg [  9:0] buffer;  // ps2_data bits
  reg [  3:0] count;  // count ps2_data bits
  reg [  2:0] ps2_clk_sync;
  reg [  7:0] pushed_num;

  reg [  7:0] scan2ascii                    [255:0];
  reg [  7:0] scan2ascii_shift              [255:0];
  reg [255:0] cache;

  initial begin
    $readmemh("resource/mem.hex", scan2ascii, 0, 255);
    $readmemh("resource/mem_shift.hex", scan2ascii_shift, 0, 255);
  end

  seg my_seg (
      .count(push_count),
      .scan_code(scan_code),
      .ascii_code(ascii_code),
      .is_shift(cache[8'h12]),
      .is_ctrl(cache[8'h14]),
      .o_seg0(o_seg0),
      .o_seg1(o_seg1),
      .o_seg2(o_seg2),
      .o_seg3(o_seg3),
      .o_seg4(o_seg4),
      .o_seg5(o_seg5),
      .o_seg6(o_seg6),
      .o_seg7(o_seg7)
  );

  always @(posedge clk) begin
    ps2_clk_sync <= {ps2_clk_sync[1:0], ps2_clk};
  end

  wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

  always @(posedge clk) begin
    if (resetn == 0) begin  // reset
      cache <= 0;
      count <= 0;
      push_count <= 0;
      scan_code <= 0;
      ascii_code <= 0;
      pushed_num <= 0;
    end else begin
      if (sampling) begin
        if (count == 4'd10) begin
          if ((buffer[0] == 0) &&  // start bit
              (ps2_data) &&  // stop bit
              (^buffer[9:1])) begin  // odd  parity
            // $display("key %x", buffer[8:1]);
            if (cache[8'hf0] == 1) begin
              pushed_num <= pushed_num - 1;
              cache[buffer[8:1]] <= 0;
              cache[8'hf0] <= 0;
            end else if (cache[buffer[8:1]] == 0) begin
              cache[buffer[8:1]] <= 1;
              if (buffer[8:1] != 8'hf0) begin
                pushed_num <= pushed_num + 1;
                push_count <= push_count + 1;
                scan_code  <= buffer[8:1];
                if (cache[8'h12] == 1) ascii_code <= scan2ascii_shift[buffer[8:1]];
                else ascii_code <= scan2ascii[buffer[8:1]];
              end
            end
          end
          count <= 0;  // for next
        end else begin
          buffer[count] <= ps2_data;  // store ps2_data
          count <= count + 3'b1;
        end
      end
    end
  end

  always @(posedge clk) begin
    if (pushed_num == 0) begin
      scan_code  <= 0;
      ascii_code <= 0;
    end
  end

endmodule

// 第一位为CTRL位，第二位为SHIFT位

// 无冲突 ascii值正常

// 支持组合键，支持输入大写字符

// 大写字符显示ascii正常
