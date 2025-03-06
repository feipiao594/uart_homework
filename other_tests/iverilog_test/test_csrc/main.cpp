// DESCRIPTION: Verilator: Verilog example module
//
// This file ONLY is placed under the Creative Commons Public Domain, for
// any use, without warranty, 2017 by Wilson Snyder.
// SPDX-License-Identifier: CC0-1.0
//======================================================================

// include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <iostream>

// Include common routines
#include <verilated.h>

#include <verilated_vcd_c.h> //可选，如果要导出vcd则需要加上

// Include model header, generated from Verilating "top.v"
#include "Vtop.h"

int main(int argc, char **argv, char **env)
{
    // See a similar example walkthrough in the verilator manpage.

    // This is intended to be a minimal example.  Before copying this to start a
    // real project, it is better to start with a more complete example,
    // e.g. examples/c_tracing.

    // Prevent unused variable warnings
    if (false && argc && argv && env)
    {
    }

    // Construct the Verilated model, from Vtop.h generated from Verilating "top.v"
    VerilatedContext *contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vtop *top = new Vtop{contextp};

    VerilatedVcdC *tfp = new VerilatedVcdC; // 初始化VCD对象指针
    contextp->traceEverOn(true);            // 打开追踪功能
    top->trace(tfp, 0);                     //
    tfp->open("wave.vcd");                  // 设置输出的文件wave.vcd

    int clk = 0;

    #include "sim_context.temp"

    // Simulate until $finish
    while (!contextp->gotFinish())
    {

        #include "sim_loop.temp"

        // 评估电路
        top->eval();

        // 记录 VCD 波形
        tfp->dump(contextp->time());

        // 推动仿真时间
        contextp->timeInc(1);

        // 时钟切换
        clk++;
    }

    // Final model cleanup
    top->final();

    // Destroy model
    delete top;

    tfp->close();
    delete contextp;
    // Return good completion status
    return 0;
}