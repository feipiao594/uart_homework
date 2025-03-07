#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <iostream>

#include "Vtop.h"

/* begin of related init data */

int reset_counter = 10;

bool max_reached_flag = false;

/* end of related init data */

void simulate_loop(Vtop *top, int clk)
{
    // 产生时钟信号
    top->clk = clk % 2;

    // 复位逻辑
    if (reset_counter > 0)
    {
        top->rst_n = 0; // 复位低有效
        reset_counter--;
    }
    else
    {
        top->rst_n = 1;
    }

    // 触发输入信号
    if (clk == 200 - 1)
        top->s3 = 1; // 测试 data_index + 1
    else
        top->s3 = 0;

    if (clk == 400 - 1)
        top->s0 = 1; // 测试 data_index - 1
    else
        top->s0 = 0;

    if (clk == 600 - 1)
        top->s4 = 1; // 测试 data_ram[data_index]++
    else
        top->s4 = 0;

    if (clk == 800 - 1)
        top->s1 = 1; // 测试 data_ram[data_index]--
    else
        top->s1 = 0;

    if (clk == 1000 - 1)
        top->s2 = 1; // 触发发送
    else
        top->s2 = 0;

    // 计算模块仿真
    top->eval();

    // 输出状态信息
    std::cout << "Cycle: " << clk
              << " | clk: " << (int)top->clk
              << " | rst_n: " << (int)top->rst_n
              << " | s3: " << (int)top->s3
              << " | s0: " << (int)top->s0
              << " | s4: " << (int)top->s4
              << " | s1: " << (int)top->s1
              << " | s2: " << (int)top->s2
              << " | send_data: " << (int)top->send_data
              << " | preview_data: " << (int)top->preview_data
              << " | data_valid: " << (int)top->data_valid
              << std::endl;
}