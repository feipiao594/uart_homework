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
    CData/*7:0*/ top__DOT__my_uart_tester__DOT__input_data;
    CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_sender_controller__DOT__data_index;
    CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_sender_controller__DOT__s3_prev;
    CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_sender_controller__DOT__s0_prev;
    CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_sender_controller__DOT__s4_prev;
    CData/*0:0*/ top__DOT__my_uart_tester__DOT__my_sender_controller__DOT__s1_prev;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT16(ledr,15,0);
    SData/*9:0*/ top__DOT__my_vga_ctrl__DOT__x_cnt;
    SData/*9:0*/ top__DOT__my_vga_ctrl__DOT__y_cnt;
    IData/*31:0*/ top__DOT__my_led__DOT__count;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*23:0*/, 524288> top__DOT__my_vmem__DOT__vga_mem;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr VlUnpacked<CData/*7:0*/, 16> top__DOT__my_uart_tester__DOT__my_lcd_double__DOT__high_lcd_single__DOT__hex_display = {{
        0xfcU, 0x60U, 0xdaU, 0xf2U, 0x66U, 0xb6U, 0xbeU, 0xe0U,
        0xfeU, 0xf6U, 0xeeU, 0x3eU, 0x9cU, 0x7aU, 0x9eU, 0x8eU
    }};
    static constexpr VlUnpacked<CData/*7:0*/, 16> top__DOT__my_uart_tester__DOT__my_lcd_double__DOT__low_lcd_single__DOT__hex_display = {{
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
