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
    // Init
    CData/*7:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__m_lcd_double__data;
    top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__m_lcd_double__data = 0;
    // Body
    vlSelf->VGA_CLK = vlSelf->clk;
    vlSelf->uart_tx = vlSelf->uart_rx;
    vlSelf->ledr = (((IData)(vlSelf->sw) << 8U) | (
                                                   (0xe0U 
                                                    & (IData)(vlSelf->top__DOT__my_led__DOT__led)) 
                                                   | (0x1fU 
                                                      & ((IData)(vlSelf->top__DOT__my_led__DOT__led) 
                                                         ^ (IData)(vlSelf->btn)))));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__parser_buffer__rd_en 
        = ((IData)(vlSelf->btn) & ((0U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count)) 
                                   & (IData)(vlSelf->sw)));
    top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__m_lcd_double__data 
        = ((1U & (IData)(vlSelf->sw)) ? (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receive_data)
            : (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__preview_data));
    vlSelf->seg0 = (0xffU & (~ vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_lcd_double__DOT__low_lcd_single__DOT__hex_display
                             [(0xfU & (IData)(top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__m_lcd_double__data))]));
    vlSelf->seg1 = (0xffU & (~ vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_lcd_double__DOT__high_lcd_single__DOT__hex_display
                             [(0xfU & ((IData)(top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__m_lcd_double__data) 
                                       >> 4U))]));
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
    CData/*7:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__m_lcd_double__data;
    top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__m_lcd_double__data = 0;
    QData/*63:0*/ top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_buf;
    top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_buf = 0;
    CData/*7:0*/ __Vdly__top__DOT__my_led__DOT__led;
    __Vdly__top__DOT__my_led__DOT__led = 0;
    IData/*31:0*/ __Vdly__top__DOT__my_led__DOT__count;
    __Vdly__top__DOT__my_led__DOT__count = 0;
    SData/*9:0*/ __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt;
    __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = 0;
    SData/*9:0*/ __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt;
    __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt = 0;
    CData/*2:0*/ __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index = 0;
    CData/*2:0*/ __Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v0;
    __Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v0 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v0;
    __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v0;
    __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v1;
    __Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v1 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v1;
    __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v1 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v1;
    __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v1 = 0;
    VlWide<4>/*103:0*/ __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg;
    VL_ZERO_W(104, __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg);
    CData/*0:0*/ __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__busy;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__busy = 0;
    CData/*5:0*/ __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__counter;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__counter = 0;
    CData/*3:0*/ __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count = 0;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory__v0;
    __Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory__v0 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory__v0;
    __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory__v0;
    __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory__v0 = 0;
    CData/*1:0*/ __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__state;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__state = 0;
    CData/*3:0*/ __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__bit_cnt;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__bit_cnt = 0;
    SData/*9:0*/ __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__shift_reg;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__shift_reg = 0;
    IData/*31:0*/ __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_gen__DOT__counter;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_gen__DOT__counter = 0;
    CData/*1:0*/ __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__state;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__state = 0;
    CData/*3:0*/ __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__bit_cnt;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__bit_cnt = 0;
    IData/*31:0*/ __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_gen__DOT__counter;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_gen__DOT__counter = 0;
    CData/*3:0*/ __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count = 0;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__memory__v0;
    __Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__memory__v0 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__memory__v0;
    __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__memory__v0;
    __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__memory__v0 = 0;
    CData/*7:0*/ __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum = 0;
    CData/*3:0*/ __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_cnt;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_cnt = 0;
    CData/*2:0*/ __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state = 0;
    CData/*3:0*/ __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count = 0;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory__v0;
    __Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory__v0 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory__v0;
    __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory__v0;
    __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory__v0 = 0;
    VlWide<3>/*95:0*/ __Vtemp_8;
    // Body
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_gen__DOT__counter 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_gen__DOT__counter;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_gen__DOT__counter 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_gen__DOT__counter;
    __Vdly__top__DOT__my_led__DOT__count = vlSelf->top__DOT__my_led__DOT__count;
    __Vdly__top__DOT__my_led__DOT__led = vlSelf->top__DOT__my_led__DOT__led;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_cnt 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_cnt;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__bit_cnt 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__bit_cnt;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__state 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__state;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__counter 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__counter;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__busy 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__busy;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[0U] 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[0U];
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[1U] 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[1U];
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[2U] 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[2U];
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[3U] 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[3U];
    __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__memory__v0 = 0U;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count;
    __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt = vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt;
    __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index;
    __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory__v0 = 0U;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count;
    __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v0 = 0U;
    __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v1 = 0U;
    __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory__v0 = 0U;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__shift_reg 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__shift_reg;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__bit_cnt 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__bit_cnt;
    __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__state 
        = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__state;
    if (vlSelf->rst) {
        __Vdly__top__DOT__my_led__DOT__led = 1U;
        __Vdly__top__DOT__my_led__DOT__count = 0U;
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
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__receiver_buffer__wr_en) 
                     & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__full))))) {
        VL_WRITEF_NX("[buffer] write data: %3#\n",0,
                     8,vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_data);
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count 
            = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count)));
        __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__memory__v0 
            = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_data;
        __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__memory__v0 = 1U;
        __Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__memory__v0 
            = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__write_pointer;
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__write_pointer 
            = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__write_pointer)));
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__pf_empty))))) {
        VL_WRITEF_NX("[buffer] read data: %x, count: %2#\n",0,
                     8,vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__memory
                     [vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__read_pointer],
                     4,vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count);
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__read_pointer 
            = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__read_pointer)));
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count 
            = (0xfU & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count) 
                       - (IData)(1U)));
    }
    if (vlSelf->rst) {
        __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = 1U;
        __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt = 1U;
    } else if ((0x320U == (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt))) {
        __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt = 
            ((0x20dU == (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt))
              ? 1U : (0x3ffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt))));
        __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = 1U;
    } else {
        __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = 
            (0x3ffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt)));
    }
    if ((((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__receiver_buffer__wr_en) 
          & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__pf_empty))) 
         & (~ ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__full) 
               | (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__pf_empty))))) {
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count 
            = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count;
    }
    if ((1U & (~ (IData)(vlSelf->sw)))) {
        if ((1U & (((IData)(vlSelf->btn) >> 3U) & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s3_prev))))) {
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index 
                = (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index)));
            vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__preview_data 
                = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                [(7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index)))];
        } else if ((1U & ((IData)(vlSelf->btn) & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s0_prev))))) {
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index 
                = (7U & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index) 
                         - (IData)(1U)));
            vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__preview_data 
                = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                [(7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index)))];
        }
        if ((IData)((((IData)(vlSelf->btn) >> 4U) & 
                     (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s4_prev))))) {
            __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v0 
                = (0xffU & ((IData)(1U) + vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                            [vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index]));
            __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v0 = 1U;
            __Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v0 
                = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index;
            vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__preview_data 
                = (0xffU & ((IData)(1U) + vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                            [vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index]));
        } else if ((1U & (((IData)(vlSelf->btn) >> 1U) 
                          & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s1_prev))))) {
            __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v1 
                = (0xffU & (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                            [vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index] 
                            - (IData)(1U)));
            __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v1 = 1U;
            __Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v1 
                = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index;
            vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__preview_data 
                = (0xffU & (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                            [vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index] 
                            - (IData)(1U)));
        }
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_data_valid) 
                     & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__full))))) {
        VL_WRITEF_NX("[buffer] write data: %3#\n",0,
                     8,vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_out_data);
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count 
            = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count)));
        __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory__v0 
            = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_out_data;
        __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory__v0 = 1U;
        __Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory__v0 
            = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__write_pointer;
        if ((0U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count))) {
            vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receive_data 
                = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_out_data;
        }
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__write_pointer 
            = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__write_pointer)));
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__parser_buffer__rd_en) 
                     & (0U != (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count))))) {
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receive_data 
            = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory
            [(0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__read_pointer)))];
        VL_WRITEF_NX("[buffer] read data: %x, count: %2#\n",0,
                     8,vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory
                     [vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__read_pointer],
                     4,vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count);
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__read_pointer 
            = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__read_pointer)));
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count 
            = (0xfU & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count) 
                       - (IData)(1U)));
    }
    if ((((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_data_valid) 
          & (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__parser_buffer__rd_en)) 
         & (~ ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__full) 
               | (0U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count)))))) {
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count 
            = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count;
    }
    if ((2U & (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__state))) {
        if ((1U & (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__state))) {
            if (VL_UNLIKELY(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_tick)) {
                VL_WRITEF_NX("[uart sender] STOP, send: %1#\n",0,
                             1,(1U & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__shift_reg) 
                                      >> 9U)));
                vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__txBusy = 0U;
                __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__state = 0U;
            }
        } else if (VL_UNLIKELY(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_tick)) {
            VL_WRITEF_NX("[uart sender] DATA, send: %1#\n",0,
                         1,(1U & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__shift_reg) 
                                  >> 9U)));
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__bit_cnt 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__bit_cnt)));
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__shift_reg 
                = (0x3feU & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__shift_reg) 
                             << 1U));
            if ((7U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__bit_cnt))) {
                __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__state = 3U;
            }
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__state))) {
        if (VL_UNLIKELY(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_tick)) {
            VL_WRITEF_NX("[uart sender] START, send: %1#\n",0,
                         1,(1U & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__shift_reg) 
                                  >> 9U)));
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__shift_reg 
                = (0x3feU & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__shift_reg) 
                             << 1U));
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__state = 2U;
        }
    } else {
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__txBusy = 0U;
        if (VL_UNLIKELY((0U != (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count)))) {
            VL_WRITEF_NX("[uart sender] IDLE, get data: %x\n",0,
                         8,vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_data);
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__shift_reg 
                = (1U | ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_data) 
                         << 1U));
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__bit_cnt = 0U;
            vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__txBusy = 1U;
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__state = 1U;
        }
    }
    vlSelf->top__DOT__my_led__DOT__count = __Vdly__top__DOT__my_led__DOT__count;
    vlSelf->top__DOT__my_led__DOT__led = __Vdly__top__DOT__my_led__DOT__led;
    if (__Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__memory__v0) {
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__memory[__Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__memory__v0] 
            = __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__memory__v0;
    }
    vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt = __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt;
    vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt = __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_index;
    if (__Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory__v0) {
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory[__Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory__v0] 
            = __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__memory__v0;
    }
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__state 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__state;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__bit_cnt 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__bit_cnt;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__shift_reg 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__shift_reg;
    vlSelf->ledr = (((IData)(vlSelf->sw) << 8U) | (
                                                   (0xe0U 
                                                    & (IData)(vlSelf->top__DOT__my_led__DOT__led)) 
                                                   | (0x1fU 
                                                      & ((IData)(vlSelf->top__DOT__my_led__DOT__led) 
                                                         ^ (IData)(vlSelf->btn)))));
    if ((2U & (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__state))) {
        if ((1U & (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__state))) {
            if (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart_tx) {
                vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_data 
                    = (0xffU & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__shift_reg) 
                                >> 1U));
                vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_data_valid 
                    = (0U != (0xffU & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__shift_reg) 
                                       >> 1U)));
            }
            vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__rxDone = 1U;
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__state = 0U;
        } else if (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_tick) {
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__bit_cnt 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__bit_cnt)));
            vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__shift_reg 
                = ((0x3feU & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__shift_reg) 
                              << 1U)) | (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart_tx));
            if ((8U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__bit_cnt))) {
                __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__state = 3U;
            }
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__state))) {
        if (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart_tx) {
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__state = 0U;
        } else if (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_tick) {
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__state = 2U;
        }
    } else {
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__rxDone = 0U;
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__bit_cnt = 0U;
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__state = 1U;
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_data_valid = 0U;
    }
    vlSelf->VGA_HSYNC = (0x60U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt));
    top__DOT__my_vga_ctrl__DOT__h_valid = ((0x90U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt)) 
                                           & (0x310U 
                                              >= (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt)));
    vlSelf->VGA_VSYNC = (2U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt));
    top__DOT__my_vga_ctrl__DOT__v_valid = ((0x23U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt)) 
                                           & (0x203U 
                                              >= (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt)));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__full 
        = (0xfU == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_buffer__DOT__count));
    top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__m_lcd_double__data 
        = ((1U & (IData)(vlSelf->sw)) ? (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receive_data)
            : (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__preview_data));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_out_data = 0U;
    if ((1U & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__busy)))) {
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_out_data = 0U;
    }
    if ((0U != (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count))) {
        if ((0U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state))) {
            vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_data_valid = 0U;
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum = 0U;
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_cnt = 0U;
            vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_out_data = 0U;
            top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_buf = 0ULL;
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state = 1U;
        } else if ((1U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state))) {
            if ((0x52U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_in_data))) {
                __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum 
                    = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_in_data;
                __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state = 2U;
            }
        } else if ((2U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state))) {
            if ((0xeU == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_in_data))) {
                __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum 
                    = (0xffU & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum) 
                                + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_in_data)));
                __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state = 3U;
            }
        } else if ((3U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state))) {
            if ((1U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_in_data))) {
                __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum 
                    = (0xffU & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum) 
                                + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_in_data)));
                __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state = 4U;
            }
        } else if ((4U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state))) {
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum 
                = (0xffU & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum) 
                            + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_in_data)));
            top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_buf 
                = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                          ((IData)(7U) 
                                                           - (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_cnt)), 3U)))) 
                    & top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_buf) 
                   | ((QData)((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_in_data)) 
                      << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                ((IData)(7U) 
                                                 - (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_cnt)), 3U))));
            if ((7U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_cnt))) {
                __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state = 5U;
            }
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_cnt 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_cnt)));
        } else if ((5U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state))) {
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum 
                = (0xffU & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum) 
                            + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_in_data)));
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state = 6U;
        } else if ((6U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state))) {
            if ((0x9aU != (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_in_data))) {
                __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state = 0U;
                vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_data_valid = 0U;
            }
            vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_data_valid = 1U;
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state = 0U;
        }
    } else {
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state = 0U;
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_data_valid = 0U;
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum = 0U;
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_cnt = 0U;
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__parser_out_data = 0U;
        top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_buf = 0ULL;
    }
    if ((vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_gen__DOT__counter 
         == (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_gen__DOT__baud_div 
             - (IData)(1U)))) {
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_gen__DOT__counter = 0U;
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_tick = 1U;
    } else {
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_gen__DOT__counter 
            = ((IData)(1U) + vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_gen__DOT__counter);
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_tick = 0U;
    }
    if ((1U & (~ (IData)(vlSelf->sw)))) {
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s3_prev 
            = (1U & ((IData)(vlSelf->btn) >> 3U));
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s0_prev 
            = (1U & (IData)(vlSelf->btn));
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s4_prev 
            = (1U & ((IData)(vlSelf->btn) >> 4U));
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s1_prev 
            = (1U & ((IData)(vlSelf->btn) >> 1U));
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sc_data_valid) 
                     & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__full))))) {
        VL_WRITEF_NX("[buffer] write data: %3#\n",0,
                     8,vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sc_send_data);
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count 
            = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count)));
        __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory__v0 
            = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sc_send_data;
        __Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory__v0 = 1U;
        __Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory__v0 
            = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__write_pointer;
        if (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sf_empty) {
            vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_data 
                = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sc_send_data;
        }
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__write_pointer 
            = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__write_pointer)));
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__sender_buffer__rd_en) 
                     & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sf_empty))))) {
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_data 
            = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory
            [(0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__read_pointer)))];
        VL_WRITEF_NX("[buffer] read data: %x, count: %2#\n",0,
                     8,vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory
                     [vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__read_pointer],
                     4,vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count);
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__read_pointer 
            = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__read_pointer)));
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count 
            = (0xfU & ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count) 
                       - (IData)(1U)));
    }
    if ((((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sc_data_valid) 
          & (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__sender_buffer__rd_en)) 
         & (~ ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__full) 
               | (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sf_empty))))) {
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count 
            = vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count;
    }
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__state 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__state;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__bit_cnt 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__bit_cnt;
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
    vlSelf->seg0 = (0xffU & (~ vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_lcd_double__DOT__low_lcd_single__DOT__hex_display
                             [(0xfU & (IData)(top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__m_lcd_double__data))]));
    vlSelf->seg1 = (0xffU & (~ vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_lcd_double__DOT__high_lcd_single__DOT__hex_display
                             [(0xfU & ((IData)(top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__m_lcd_double__data) 
                                       >> 4U))]));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__checksum;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_cnt 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__data_cnt;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__state;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_gen__DOT__counter 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_gen__DOT__counter;
    if (__Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory__v0) {
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory[__Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory__v0] 
            = __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__memory__v0;
    }
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__receiver_buffer__wr_en 
        = ((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_data_valid) 
           & (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__rxDone));
    if ((vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_gen__DOT__counter 
         == (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_gen__DOT__baud_div 
             - (IData)(1U)))) {
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_gen__DOT__counter = 0U;
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_tick = 1U;
    } else {
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_gen__DOT__counter 
            = ((IData)(1U) + vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_gen__DOT__counter);
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_tick = 0U;
    }
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
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_parser__DOT__busy = 0U;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__pf_empty 
        = (0U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__full 
        = (0xfU == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__parser_buffer__rd_en 
        = ((IData)(vlSelf->btn) & ((0U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__receiver_buffer__DOT__count)) 
                                   & (IData)(vlSelf->sw)));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender__DOT__baud_gen__DOT__baud_div = 0x1b2U;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sf_empty 
        = (0U == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__full 
        = (0xfU == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count));
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT____Vcellinp__sender_buffer__rd_en 
        = ((0U != (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sender_buffer__DOT__count)) 
           & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__txBusy)));
    if (((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__send_signal) 
         & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__busy)))) {
        __Vtemp_8[0U] = (IData)((((QData)((IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
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
                                                                                ((IData)(0xf9U) 
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
        __Vtemp_8[1U] = (IData)(((((QData)((IData)(
                                                   vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
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
                                                                                ((IData)(0xf9U) 
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
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[0U] 
            = __Vtemp_8[0U];
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[1U] 
            = __Vtemp_8[1U];
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[2U] 
            = ((0xffffff00U & (0xc010000U | (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                             [0U] << 8U))) 
               | vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
               [1U]);
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[3U] 
            = (0xffU & (0x52U | (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram
                                 [0U] >> 0x18U)));
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__busy = 1U;
    } else if (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__busy) {
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__counter 
            = (0x3fU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__counter)));
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sc_send_data 
            = (0xffU & vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[3U]);
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sc_data_valid = 1U;
        if ((0xcU == (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__counter))) {
            __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__busy = 0U;
        }
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[0U] 
            = (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[0U] 
               << 8U);
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[1U] 
            = ((vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[0U] 
                >> 0x18U) | (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[1U] 
                             << 8U));
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[2U] 
            = ((vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[1U] 
                >> 0x18U) | (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[2U] 
                             << 8U));
        __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[3U] 
            = (vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[2U] 
               >> 0x18U);
    }
    if ((1U & (~ (IData)(vlSelf->sw)))) {
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__send_signal 
            = (1U & (((IData)(vlSelf->btn) >> 2U) & 
                     (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s2_prev))));
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__s2_prev 
            = (1U & ((IData)(vlSelf->btn) >> 2U));
    }
    if ((1U & (~ (IData)(vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__busy)))) {
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sc_data_valid = 0U;
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__sc_send_data = 0U;
    }
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_gen__DOT__counter 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_gen__DOT__counter;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[0U] 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[0U];
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[1U] 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[1U];
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[2U] 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[2U];
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[3U] 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__shift_reg[3U];
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__busy 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__busy;
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__counter 
        = __Vdly__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__P2S__DOT__counter;
    if (__Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v0) {
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram[__Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v0] 
            = __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v0;
    }
    if (__Vdlyvset__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v1) {
        vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram[__Vdlyvdim0__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v1] 
            = __Vdlyvval__top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_sender_controller__DOT__data_ram__v1;
    }
    vlSelf->top__DOT__my_uart_tester__DOT__my_communication_uart__DOT__m_receiver__DOT__baud_gen__DOT__baud_div = 0x1b2U;
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
            VL_FATAL_MT("/home/feipiao/Workplace/gitclone/uart_homework/other_tests/nvboard_test/vsrc/top.v", 1, "", "Input combinational region did not converge.");
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
            VL_FATAL_MT("/home/feipiao/Workplace/gitclone/uart_homework/other_tests/nvboard_test/vsrc/top.v", 1, "", "NBA region did not converge.");
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
                VL_FATAL_MT("/home/feipiao/Workplace/gitclone/uart_homework/other_tests/nvboard_test/vsrc/top.v", 1, "", "Active region did not converge.");
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
