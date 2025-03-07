#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <iostream>

#include "Vtop.h"

/* begin of related init data */

const int MAX_COUNT = 255; // 计数器最大值
const int RESET_TIME = 10; // 复位时间

int reset_counter = RESET_TIME; // 复位倒计时
int inc_counter = 0;            // 记录加计数次数
int dec_counter = 0;            // 记录减计数次数
bool max_reached_flag = false;  // 是否达到最大值

/* end of related init data */

void simulate_loop(Vtrans_counter *top, int clk)
{
    // 生成时钟信号
    top->clk = clk % 2;

    // 复位阶段
    if (reset_counter > 0)
    {
        top->rst = 1; // 复位
        reset_counter--;
        max_reached_flag = false;
    }
    else
    {
        top->rst = 0; // 复位完成
    }

    // **加计数**
    if (reset_counter == 0 && inc_counter < MAX_COUNT / 2)
    {
        top->inc = 1;
        inc_counter++;
    }
    else
    {
        top->inc = 0;
    }

    // **减计数**
    if (inc_counter >= MAX_COUNT / 4 && dec_counter < MAX_COUNT / 4)
    {
        top->dec = 1;
        dec_counter++;
    }
    else
    {
        top->dec = 0;
    }

    // **最大值检测**
    if (top->max_reached)
    {
        max_reached_flag = true;
    }

    // **仿真信息输出**
    std::cout << "Time: " << contextp->time()
              << " | clk: " << top->clk
              << " | rst: " << top->rst
              << " | inc: " << top->inc
              << " | dec: " << top->dec
              << " | max_reached: " << top->max_reached
              << std::endl;
}