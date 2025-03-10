// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        VL_IN8(btn,4,0);
        VL_IN8(sw,7,0);
        VL_IN8(ps2_clk,0,0);
        VL_IN8(ps2_data,0,0);
        VL_IN8(uart_rx,0,0);
        VL_OUT8(uart_tx,0,0);
        VL_OUT8(VGA_CLK,0,0);
        VL_OUT8(VGA_HSYNC,0,0);
        VL_OUT8(VGA_VSYNC,0,0);
        VL_OUT8(VGA_BLANK_N,0,0);
        VL_OUT8(VGA_R,7,0);
        VL_OUT8(VGA_G,7,0);
        VL_OUT8(VGA_B,7,0);
        VL_OUT8(seg0,7,0);
        VL_OUT8(seg1,7,0);
        VL_OUT8(seg2,7,0);
        VL_OUT8(seg3,7,0);
        VL_OUT8(seg4,7,0);
        VL_OUT8(seg5,7,0);
        VL_OUT8(seg6,7,0);
        VL_OUT8(seg7,7,0);
        CData/*7:0*/ top__DOT__my_led__DOT__led;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart_tx;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__txBusy;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__rxDone;
        CData/*7:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__preview_data;
        CData/*7:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receive_data;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sc_data_valid;
        CData/*7:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sc_send_data;
        CData/*7:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_data;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sf_empty;
        CData/*7:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_data;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_data_valid;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_data_valid;
        CData/*7:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_in_data;
        CData/*7:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_out_data;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__pf_empty;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__sender_buffer__rd_en;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__receiver_buffer__wr_en;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__parser_buffer__rd_en;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__busy;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__send_signal;
        CData/*2:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s3_prev;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s0_prev;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s4_prev;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s1_prev;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s2_prev;
        CData/*5:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__counter;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__full;
        CData/*3:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__write_pointer;
        CData/*3:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__read_pointer;
        CData/*3:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count;
        CData/*3:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__bit_cnt;
        CData/*1:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__state;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_tick;
        CData/*3:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__bit_cnt;
        CData/*1:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__state;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_tick;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__full;
        CData/*3:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__write_pointer;
        CData/*3:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__read_pointer;
    };
    struct {
        CData/*3:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count;
        CData/*2:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state;
        CData/*7:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum;
        CData/*3:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_cnt;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__busy;
        CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__full;
        CData/*3:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__write_pointer;
        CData/*3:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__read_pointer;
        CData/*3:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __VactContinue;
        VL_OUT16(ledr,15,0);
        SData/*9:0*/ top__DOT__my_vga_ctrl__DOT__x_cnt;
        SData/*9:0*/ top__DOT__my_vga_ctrl__DOT__y_cnt;
        SData/*9:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__shift_reg;
        SData/*9:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__shift_reg;
        IData/*31:0*/ top__DOT__my_led__DOT__count;
        VlWide<4>/*103:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg;
        IData/*31:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_gen__DOT__baud_div;
        IData/*31:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_gen__DOT__counter;
        IData/*31:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_gen__DOT__baud_div;
        IData/*31:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_gen__DOT__counter;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*7:0*/, 8> top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram;
        VlUnpacked<CData/*7:0*/, 16> top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory;
        VlUnpacked<CData/*7:0*/, 16> top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__memory;
        VlUnpacked<CData/*7:0*/, 16> top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory;
        VlUnpacked<IData/*23:0*/, 524288> top__DOT__my_vmem__DOT__vga_mem;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr VlUnpacked<CData/*7:0*/, 16> top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_lcd_double__DOT__high_lcd_single__DOT__hex_display = {{
        0xfcU, 0x60U, 0xdaU, 0xf2U, 0x66U, 0xb6U, 0xbeU, 0xe0U,
        0xfeU, 0xf6U, 0xeeU, 0x3eU, 0x9cU, 0x7aU, 0x9eU, 0x8eU
    }};
    static constexpr VlUnpacked<CData/*7:0*/, 16> top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_lcd_double__DOT__low_lcd_single__DOT__hex_display = {{
        0xfcU, 0x60U, 0xdaU, 0xf2U, 0x66U, 0xb6U, 0xbeU, 0xe0U,
        0xfeU, 0xf6U, 0xeeU, 0x3eU, 0x9cU, 0x7aU, 0x9eU, 0x8eU
    }};

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
