// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    // Body
    Vtop___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__write_pointer = 0U;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__read_pointer = 0U;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count = 0U;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__write_pointer = 0U;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__read_pointer = 0U;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count = 0U;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__write_pointer = 0U;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__read_pointer = 0U;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count = 0U;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__my_uart_tester__DOT____Vcellinp__my_communication_uart__rst_n__0 
        = vlSelf->top__DOT__my_uart_tester__DOT____Vcellinp__my_communication_uart__rst_n;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_1;
    // Body
    vlSelf->seg2 = 0xffU;
    vlSelf->seg3 = 0xffU;
    vlSelf->seg4 = 0xffU;
    vlSelf->seg5 = 0xffU;
    vlSelf->seg6 = 0xffU;
    vlSelf->seg7 = 0xffU;
    __Vtemp_1[0U] = 0x2e686578U;
    __Vtemp_1[1U] = 0x74757265U;
    __Vtemp_1[2U] = 0x2f706963U;
    __Vtemp_1[3U] = 0x75726365U;
    __Vtemp_1[4U] = 0x7265736fU;
    VL_READMEM_N(true, 24, 524288, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_1)
                 ,  &(vlSelf->top__DOT__my_vmem__DOT__vga_mem)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/feipiao/Workplace/gitclone/uart_homework/other_tests/nvboard_test/vsrc/top.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ vlSelf->__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Init
    SData/*9:0*/ top__DOT__h_addr;
    top__DOT__h_addr = 0;
    SData/*8:0*/ top__DOT____Vcellinp__my_vmem__v_addr;
    top__DOT____Vcellinp__my_vmem__v_addr = 0;
    CData/*0:0*/ top__DOT__my_vga_ctrl__DOT__h_valid;
    top__DOT__my_vga_ctrl__DOT__h_valid = 0;
    CData/*0:0*/ top__DOT__my_vga_ctrl__DOT__v_valid;
    top__DOT__my_vga_ctrl__DOT__v_valid = 0;
    CData/*7:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__m_lcd_double__data;
    top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__m_lcd_double__data = 0;
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    vlSelf->VGA_CLK = vlSelf->clk;
    vlSelf->top__DOT__my_uart_tester__DOT____Vcellinp__my_communication_uart__rst_n 
        = (1U & (~ ((IData)(vlSelf->sw) >> 1U)));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__pf_empty 
        = (0U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__full 
        = (0xfU == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count));
    vlSelf->uart_tx = vlSelf->uart_rx;
    vlSelf->VGA_HSYNC = (0x60U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt));
    vlSelf->VGA_VSYNC = (2U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sf_empty 
        = (0U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__full 
        = (0xfU == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__rf_empty 
        = (0U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__full 
        = (0xfU == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count));
    __Vtemp_1[0U] = (IData)((((QData)((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                              [2U])) 
                              << 0x38U) | (((QData)((IData)(
                                                            vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                            [3U])) 
                                            << 0x30U) 
                                           | (((QData)((IData)(
                                                               vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                               [4U])) 
                                               << 0x28U) 
                                              | (((QData)((IData)(
                                                                  vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                  [5U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   (0x9aU 
                                                                    | ((vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                        [6U] 
                                                                        << 0x18U) 
                                                                       | ((vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                           [7U] 
                                                                           << 0x10U) 
                                                                          | (0xff00U 
                                                                             & ((~ 
                                                                                ((IData)(0xfaU) 
                                                                                + 
                                                                                (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                                [0U] 
                                                                                + 
                                                                                (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                                [1U] 
                                                                                + 
                                                                                (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                                [2U] 
                                                                                + 
                                                                                (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                                [3U] 
                                                                                + 
                                                                                (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                                [4U] 
                                                                                + 
                                                                                (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                                [5U] 
                                                                                + 
                                                                                (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                                [6U] 
                                                                                + 
                                                                                vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                                [7U]))))))))) 
                                                                                << 8U))))))))))));
    __Vtemp_1[1U] = (IData)(((((QData)((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                               [2U])) 
                               << 0x38U) | (((QData)((IData)(
                                                             vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                             [3U])) 
                                             << 0x30U) 
                                            | (((QData)((IData)(
                                                                vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                [4U])) 
                                                << 0x28U) 
                                               | (((QData)((IData)(
                                                                   vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                   [5U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    (0x9aU 
                                                                     | ((vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                         [6U] 
                                                                         << 0x18U) 
                                                                        | ((vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                            [7U] 
                                                                            << 0x10U) 
                                                                           | (0xff00U 
                                                                              & ((~ 
                                                                                ((IData)(0xfaU) 
                                                                                + 
                                                                                (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                                [0U] 
                                                                                + 
                                                                                (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                                [1U] 
                                                                                + 
                                                                                (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                                [2U] 
                                                                                + 
                                                                                (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                                [3U] 
                                                                                + 
                                                                                (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                                [4U] 
                                                                                + 
                                                                                (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                                [5U] 
                                                                                + 
                                                                                (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                                [6U] 
                                                                                + 
                                                                                vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                                                                [7U]))))))))) 
                                                                                << 8U))))))))))) 
                             >> 0x20U));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT____Vcellinp__P2S__parallel_in[0U] 
        = __Vtemp_1[0U];
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT____Vcellinp__P2S__parallel_in[1U] 
        = __Vtemp_1[1U];
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT____Vcellinp__P2S__parallel_in[2U] 
        = ((0xffffff00U & (0xd010000U | (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                         [0U] << 8U))) 
           | vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
           [1U]);
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT____Vcellinp__P2S__parallel_in[3U] 
        = (0xffU & (0x52U | (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                             [0U] >> 0x18U)));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__sender_buffer__rd_en 
        = ((0U != (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count)) 
           & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__txBusy)));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__receiver_buffer__rd_en 
        = (1U & ((0U != (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count)) 
                 | (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_busy))));
    vlSelf->ledr = (((IData)(vlSelf->sw) << 8U) | (
                                                   (0xe0U 
                                                    & (IData)(vlSelf->top__DOT__my_led__DOT__led)) 
                                                   | (0x1fU 
                                                      & ((IData)(vlSelf->top__DOT__my_led__DOT__led) 
                                                         ^ (IData)(vlSelf->btn)))));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__parser_buffer__rd_en 
        = ((~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__btn_0_prev)) 
           & ((IData)(vlSelf->btn) & ((0U != (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count)) 
                                      & (IData)(vlSelf->sw))));
    top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__m_lcd_double__data 
        = ((1U & (IData)(vlSelf->sw)) ? (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receive_data)
            : (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__preview_data));
    top__DOT__my_vga_ctrl__DOT__h_valid = ((0x90U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt)) 
                                           & (0x310U 
                                              >= (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt)));
    top__DOT__my_vga_ctrl__DOT__v_valid = ((0x23U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt)) 
                                           & (0x203U 
                                              >= (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt)));
    vlSelf->seg0 = (0xffU & (~ vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_lcd_double__DOT__low_lcd_single__DOT__hex_display
                             [(0xfU & (IData)(top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__m_lcd_double__data))]));
    vlSelf->seg1 = (0xffU & (~ vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_lcd_double__DOT__high_lcd_single__DOT__hex_display
                             [(0xfU & ((IData)(top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__m_lcd_double__data) 
                                       >> 4U))]));
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

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ vlSelf->__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk or negedge top.my_uart_tester.__Vcellinp__my_communication_uart__rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk or negedge top.my_uart_tester.__Vcellinp__my_communication_uart__rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = 0;
    vlSelf->rst = 0;
    vlSelf->btn = 0;
    vlSelf->sw = 0;
    vlSelf->ps2_clk = 0;
    vlSelf->ps2_data = 0;
    vlSelf->uart_rx = 0;
    vlSelf->uart_tx = 0;
    vlSelf->ledr = 0;
    vlSelf->VGA_CLK = 0;
    vlSelf->VGA_HSYNC = 0;
    vlSelf->VGA_VSYNC = 0;
    vlSelf->VGA_BLANK_N = 0;
    vlSelf->VGA_R = 0;
    vlSelf->VGA_G = 0;
    vlSelf->VGA_B = 0;
    vlSelf->seg0 = 0;
    vlSelf->seg1 = 0;
    vlSelf->seg2 = 0;
    vlSelf->seg3 = 0;
    vlSelf->seg4 = 0;
    vlSelf->seg5 = 0;
    vlSelf->seg6 = 0;
    vlSelf->seg7 = 0;
    vlSelf->top__DOT__my_led__DOT__count = 0;
    vlSelf->top__DOT__my_led__DOT__led = 0;
    vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt = 0;
    vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart_tx = 0;
    vlSelf->top__DOT__my_uart_tester__DOT____Vcellinp__my_communication_uart__rst_n = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__txBusy = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__rxDone = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__preview_data = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receive_data = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sc_data_valid = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sc_send_data = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_data = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sf_empty = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_data = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_data_valid = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__rf_empty = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_in_data = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_out_data = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__pf_empty = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_busy = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__btn_0_prev = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__sender_buffer__rd_en = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__receiver_buffer__rd_en = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__parser_buffer__rd_en = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__busy = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__send_signal = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram[__Vi0] = 0;
    }
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s3_prev = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s0_prev = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s4_prev = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s1_prev = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s2_prev = 0;
    VL_ZERO_RESET_W(104, vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT____Vcellinp__P2S__parallel_in);
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__counter = 0;
    VL_ZERO_RESET_W(104, vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg);
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__full = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory[__Vi0] = 0;
    }
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__write_pointer = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__read_pointer = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__shift_reg = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__bit_cnt = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__state = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_tick = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_gen__DOT__baud_div = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_gen__DOT__counter = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__shift_reg = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__bit_cnt = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__state = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_tick = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_gen__DOT__baud_div = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_gen__DOT__counter = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__full = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__memory[__Vi0] = 0;
    }
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__write_pointer = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__read_pointer = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_cnt = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_buf = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__busy = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__ptsEn = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__PTS__DOT__counter = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__PTS__DOT__shift_reg = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__full = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory[__Vi0] = 0;
    }
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__write_pointer = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__read_pointer = 0;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count = 0;
    for (int __Vi0 = 0; __Vi0 < 524288; ++__Vi0) {
        vlSelf->top__DOT__my_vmem__DOT__vga_mem[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__my_uart_tester__DOT____Vcellinp__my_communication_uart__rst_n__0 = 0;
}
