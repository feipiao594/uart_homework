#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <iostream>

#include "Vtop.h"

/* begin of related init data */

const int P_WIDTH = 64;                  // 并行数据宽度
const int S_WIDTH = 8;                   // 串行数据宽度
const int COUNT_MAX = P_WIDTH / S_WIDTH; // 需要多少次串行输出才能清空并行数据

int reset_counter = 10;                      // 复位时间
int shift_counter = 0;                       // 记录已经输出的串行数据块
uint64_t parallel_data = 0x123456789ABCDEF0; // 测试并行数据
bool shifting = false;

/* end of related init data */

void simulate_loop(Vtop *top, int clk)
{
    // 生成时钟信号
    top->clk = clk % 2;

    for (int i = 0; i < COUNT_MAX; i++)
    {
        parallel_data += (9 + random() % 5) * (17 + random() * 3);
    }

    // 复位阶段
    if (reset_counter > 0)
    {
        top->rst = 1; // 复位
        reset_counter--;
        shifting = false;
    }
    else
    {
        top->rst = 0; // 复位完成
    }

    // **加载并行数据**
    if (reset_counter == 0 && !top->busy)
    {
        top->load = 1;
        top->parallel_in = parallel_data;
    }
    else
    {
        top->load = 0;
    }

    // **仿真信息输出**
    std::cout << "Time: " << contextp->time()
              << " | clk: " << top->clk
              << " | rst: " << top->rst
              << " | load: " << top->load
              << " | busy: " << top->busy
              << " | parallel_in: " << (top->load ? std::to_string(top->parallel_in) : "N/A")
              << " | serial_out: " << (shifting ? std::to_string(top->serial_out) : "N/A")
              << " | valid: " << top->valid
              << std::endl;
}
