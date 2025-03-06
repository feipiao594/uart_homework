#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <iostream>

#include "Vtop.h"

/* begin of related init data */

const int S_WIDTH = 8;  // 串行数据宽度
const int P_WIDTH = 64; // 并行数据宽度
const int COUNT_MAX = P_WIDTH / S_WIDTH;

int reset_counter = 10;                                                            // 复位时间
int load_phase = 0;                                                                // 控制加载数据阶段
int serial_data_index = 0;                                                         // 记录已发送的数据量
uint8_t serial_data[COUNT_MAX] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0}; // 示例串行数据流
bool loading = false;

/* end of related init data */

void simulate_loop(Vtop *top, int clk)
{
    top->clk = clk % 2;

    for (int i = 0; i < COUNT_MAX; i++)
    {
        serial_data[i] += random() % 5;
    }

    if (reset_counter > 0)
    {
        top->rst = 1;
        reset_counter--;
        loading = false;
    }
    else
    {
        top->rst = 0;
    }

    if (reset_counter == 0 && serial_data_index < COUNT_MAX)
    {
        top->load = 1;
        top->serial_in = serial_data[serial_data_index];
        serial_data_index++;
        loading = true;
    }
    else
    {
        top->load = 0;
    }

    if (serial_data_index == COUNT_MAX)
    {
        serial_data_index = 0;
    }

    std::cout << "Time: " << contextp->time()
              << " | clk: " << top->clk
              << " | rst: " << top->rst
              << " | load: " << top->load
              << " | serial_in: " << (loading ? std::to_string(top->serial_in) : "N/A")
              << " | parallel_out: " << (top->valid ? std::to_string(top->parallel_out) : "N/A")
              << " | valid: " << top->valid
              << std::endl;
}