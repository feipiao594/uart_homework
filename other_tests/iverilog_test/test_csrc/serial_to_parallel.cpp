#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <iostream>

#include "Vtop.h"

/* begin of related init data */

int reset_counter = 10; // 复位时间

/* end of related init data */

void simulate_loop(Vtop *top, int clk)
{
    // 生成时钟信号
    top->clk = clk % 2;

    // 复位阶段
    if (reset_counter > 0)
    {
        top->rst = 1; // 复位状态
        reset_counter--;
    }
    else
    {
        top->rst = 0; // 复位完成
    }
}