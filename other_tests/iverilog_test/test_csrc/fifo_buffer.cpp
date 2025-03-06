#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <iostream>

#include "Vtop.h"

/* begin of related init data */

int reset_counter = 10; // 复位时间
int write_phase = 0;    // 控制写入阶段
int read_phase = 0;     // 控制读取阶段#include <stdio.h>
int data_in = 10;       // 输入数据
bool writing = false;
bool reading = false;

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
}