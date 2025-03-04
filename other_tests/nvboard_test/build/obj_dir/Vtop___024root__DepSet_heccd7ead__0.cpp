// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->VGA_CLK = vlSelf->clk;
    vlSelf->uart_tx = vlSelf->uart_rx;
    vlSelf->ledr = (((IData)(vlSelf->sw) << 8U) | (
                                                   (0xe0U 
                                                    & (IData)(vlSelf->top__DOT__my_led__DOT__led)) 
                                                   | (0x1fU 
                                                      & ((IData)(vlSelf->top__DOT__my_led__DOT__led) 
                                                         ^ (IData)(vlSelf->btn)))));
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*9:0*/ top__DOT__h_addr;
    top__DOT__h_addr = 0;
    SData/*8:0*/ top__DOT____Vcellinp__my_vmem__v_addr;
    top__DOT____Vcellinp__my_vmem__v_addr = 0;
    CData/*0:0*/ top__DOT__my_vga_ctrl__DOT__h_valid;
    top__DOT__my_vga_ctrl__DOT__h_valid = 0;
    CData/*0:0*/ top__DOT__my_vga_ctrl__DOT__v_valid;
    top__DOT__my_vga_ctrl__DOT__v_valid = 0;
    CData/*7:0*/ __Vdly__top__DOT__my_led__DOT__led;
    __Vdly__top__DOT__my_led__DOT__led = 0;
    IData/*31:0*/ __Vdly__top__DOT__my_led__DOT__count;
    __Vdly__top__DOT__my_led__DOT__count = 0;
    SData/*9:0*/ __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt;
    __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = 0;
    SData/*9:0*/ __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt;
    __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt = 0;
    CData/*7:0*/ __Vdly__top__DOT__my_uart_tester__DOT__input_data;
    __Vdly__top__DOT__my_uart_tester__DOT__input_data = 0;
    // Body
    __Vdly__top__DOT__my_led__DOT__count = vlSelf->top__DOT__my_led__DOT__count;
    __Vdly__top__DOT__my_led__DOT__led = vlSelf->top__DOT__my_led__DOT__led;
    __Vdly__top__DOT__my_uart_tester__DOT__input_data 
        = vlSelf->top__DOT__my_uart_tester__DOT__input_data;
    __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt = vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt;
    __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt;
    if (vlSelf->rst) {
        __Vdly__top__DOT__my_led__DOT__led = 1U;
        __Vdly__top__DOT__my_led__DOT__count = 0U;
        __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = 1U;
        __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt = 1U;
    } else {
        if ((0U == vlSelf->top__DOT__my_led__DOT__count)) {
            __Vdly__top__DOT__my_led__DOT__led = ((0xfeU 
                                                   & ((IData)(vlSelf->top__DOT__my_led__DOT__led) 
                                                      << 1U)) 
                                                  | (1U 
                                                     & ((IData)(vlSelf->top__DOT__my_led__DOT__led) 
                                                        >> 7U)));
        }
        __Vdly__top__DOT__my_led__DOT__count = ((0x4c4b40U 
                                                 <= vlSelf->top__DOT__my_led__DOT__count)
                                                 ? 0U
                                                 : 
                                                ((IData)(1U) 
                                                 + vlSelf->top__DOT__my_led__DOT__count));
        if ((0x320U == (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt))) {
            __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt 
                = ((0x20dU == (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt))
                    ? 1U : (0x3ffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt))));
            __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = 1U;
        } else {
            __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt 
                = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt)));
        }
    }
    if ((IData)((((IData)(vlSelf->btn) >> 4U) & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_sender_controller__DOT__s4_prev))))) {
        __Vdly__top__DOT__my_uart_tester__DOT__input_data 
            = ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_sender_controller__DOT__data_index)
                ? ((0xfU & (IData)(__Vdly__top__DOT__my_uart_tester__DOT__input_data)) 
                   | (0xf0U & (((IData)(1U) + ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__input_data) 
                                               >> 4U)) 
                               << 4U))) : ((0xf0U & (IData)(__Vdly__top__DOT__my_uart_tester__DOT__input_data)) 
                                           | (0xfU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__input_data)))));
    }
    if ((1U & (((IData)(vlSelf->btn) >> 1U) & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_sender_controller__DOT__s1_prev))))) {
        __Vdly__top__DOT__my_uart_tester__DOT__input_data 
            = ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_sender_controller__DOT__data_index)
                ? ((0xfU & (IData)(__Vdly__top__DOT__my_uart_tester__DOT__input_data)) 
                   | (0xf0U & ((((IData)(vlSelf->top__DOT__my_uart_tester__DOT__input_data) 
                                 >> 4U) - (IData)(1U)) 
                               << 4U))) : ((0xf0U & (IData)(__Vdly__top__DOT__my_uart_tester__DOT__input_data)) 
                                           | (0xfU 
                                              & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__input_data) 
                                                 - (IData)(1U)))));
    }
    vlSelf->top__DOT__my_led__DOT__count = __Vdly__top__DOT__my_led__DOT__count;
    vlSelf->top__DOT__my_led__DOT__led = __Vdly__top__DOT__my_led__DOT__led;
    vlSelf->top__DOT__my_uart_tester__DOT__input_data 
        = __Vdly__top__DOT__my_uart_tester__DOT__input_data;
    vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt = __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt;
    vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt = __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt;
    vlSelf->ledr = (((IData)(vlSelf->sw) << 8U) | (
                                                   (0xe0U 
                                                    & (IData)(vlSelf->top__DOT__my_led__DOT__led)) 
                                                   | (0x1fU 
                                                      & ((IData)(vlSelf->top__DOT__my_led__DOT__led) 
                                                         ^ (IData)(vlSelf->btn)))));
    vlSelf->seg0 = (0xffU & (~ vlSelf->top__DOT__my_uart_tester__DOT__my_lcd_double__DOT__low_lcd_single__DOT__hex_display
                             [(0xfU & (IData)(vlSelf->top__DOT__my_uart_tester__DOT__input_data))]));
    vlSelf->seg1 = (0xffU & (~ vlSelf->top__DOT__my_uart_tester__DOT__my_lcd_double__DOT__high_lcd_single__DOT__hex_display
                             [(0xfU & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__input_data) 
                                       >> 4U))]));
    vlSelf->top__DOT__my_uart_tester__DOT__my_sender_controller__DOT__s4_prev 
        = (1U & ((IData)(vlSelf->btn) >> 4U));
    vlSelf->top__DOT__my_uart_tester__DOT__my_sender_controller__DOT__s1_prev 
        = (1U & ((IData)(vlSelf->btn) >> 1U));
    if ((1U & (((IData)(vlSelf->btn) >> 3U) & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_sender_controller__DOT__s3_prev))))) {
        vlSelf->top__DOT__my_uart_tester__DOT__my_sender_controller__DOT__data_index = 1U;
    }
    if ((1U & ((IData)(vlSelf->btn) & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_sender_controller__DOT__s0_prev))))) {
        vlSelf->top__DOT__my_uart_tester__DOT__my_sender_controller__DOT__data_index = 0U;
    }
    vlSelf->VGA_HSYNC = (0x60U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt));
    top__DOT__my_vga_ctrl__DOT__h_valid = ((0x90U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt)) 
                                           & (0x310U 
                                              >= (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt)));
    vlSelf->VGA_VSYNC = (2U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt));
    top__DOT__my_vga_ctrl__DOT__v_valid = ((0x23U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt)) 
                                           & (0x203U 
                                              >= (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt)));
    if (top__DOT__my_vga_ctrl__DOT__h_valid) {
        top__DOT__h_addr = (0x3ffU & ((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt) 
                                      - (IData)(0x91U)));
        vlSelf->VGA_BLANK_N = top__DOT__my_vga_ctrl__DOT__v_valid;
    } else {
        top__DOT__h_addr = 0U;
        vlSelf->VGA_BLANK_N = 0U;
    }
    top__DOT____Vcellinp__my_vmem__v_addr = ((IData)(top__DOT__my_vga_ctrl__DOT__v_valid)
                                              ? (0x1ffU 
                                                 & ((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt) 
                                                    - (IData)(0x24U)))
                                              : 0U);
    vlSelf->top__DOT__my_uart_tester__DOT__my_sender_controller__DOT__s3_prev 
        = (1U & ((IData)(vlSelf->btn) >> 3U));
    vlSelf->top__DOT__my_uart_tester__DOT__my_sender_controller__DOT__s0_prev 
        = (1U & (IData)(vlSelf->btn));
    vlSelf->VGA_R = (0xffU & (vlSelf->top__DOT__my_vmem__DOT__vga_mem
                              [(((IData)(top__DOT__h_addr) 
                                 << 9U) | (IData)(top__DOT____Vcellinp__my_vmem__v_addr))] 
                              >> 0x10U));
    vlSelf->VGA_G = (0xffU & (vlSelf->top__DOT__my_vmem__DOT__vga_mem
                              [(((IData)(top__DOT__h_addr) 
                                 << 9U) | (IData)(top__DOT____Vcellinp__my_vmem__v_addr))] 
                              >> 8U));
    vlSelf->VGA_B = (0xffU & vlSelf->top__DOT__my_vmem__DOT__vga_mem
                     [(((IData)(top__DOT__h_addr) << 9U) 
                       | (IData)(top__DOT____Vcellinp__my_vmem__v_addr))]);
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/feipiao/Workplace/gitclone/uart_homework/other_tests/homework_uart/vsrc/top.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/feipiao/Workplace/gitclone/uart_homework/other_tests/homework_uart/vsrc/top.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/feipiao/Workplace/gitclone/uart_homework/other_tests/homework_uart/vsrc/top.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->btn & 0xe0U))) {
        Verilated::overWidthError("btn");}
    if (VL_UNLIKELY((vlSelf->ps2_clk & 0xfeU))) {
        Verilated::overWidthError("ps2_clk");}
    if (VL_UNLIKELY((vlSelf->ps2_data & 0xfeU))) {
        Verilated::overWidthError("ps2_data");}
    if (VL_UNLIKELY((vlSelf->uart_rx & 0xfeU))) {
        Verilated::overWidthError("uart_rx");}
}
#endif  // VL_DEBUG
