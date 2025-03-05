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
    int reset_counter = 10; // 复位时间
    int write_phase = 0;    // 控制写入阶段
    int read_phase = 0;     // 控制读取阶段
    int data_in = 10;       // 输入数据
    bool writing = false;
    bool reading = false;

    // Simulate until $finish
    while (!contextp->gotFinish())
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

        // **写入数据**
        if (reset_counter == 0 && write_phase < 5)
        {
            top->wr_en = 1;
            top->data_in = data_in;
            data_in += 10;
            write_phase++;
            writing = true;
        }
        else
        {
            top->wr_en = 0;
            writing = false;
        }

        // **读取数据**
        if (reset_counter == 0 && write_phase >= 3 && read_phase < 3)
        {
            top->rd_en = 1;
            read_phase++;
            reading = true;
        }
        else
        {
            top->rd_en = 0;
            reading = false;
        }

        // **防止写入太快，留出时间读取**
        if (write_phase >= 5 && read_phase < 3)
        {
            write_phase = 5; // 暂停写入
        }

        // **数据完全读取后，继续写入**
        if (read_phase == 3 && write_phase < 10)
        {
            write_phase++;
            top->wr_en = 1;
            top->data_in = data_in;
            data_in += 10;
            writing = true;
        }

        // **写满后，继续读取**
        if (write_phase >= 10 && read_phase < 10)
        {
            top->rd_en = 1;
            read_phase++;
            reading = true;
        }

        // **当 FIFO 完全读完时，重新开始写入**
        if (read_phase == 10)
        {
            write_phase = 0;
            read_phase = 0;
            data_in = 10;
        }

        // **仿真信息输出**
        std::cout << "Time: " << contextp->time()
                  << " | clk: " << top->clk
                  << " | rst: " << top->rst
                  << " | wr_en: " << top->wr_en
                  << " | rd_en: " << top->rd_en
                  << " | data_in: " << (writing ? std::to_string(top->data_in) : "N/A")
                  << " | data_out: " << (reading ? std::to_string(top->data_out) : "N/A")
                  << " | full: " << top->full
                  << " | empty: " << top->empty
                  << std::endl;

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