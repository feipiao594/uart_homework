// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

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
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__top__DOT__m_fifo_buffer__DOT__write_pointer;
    __Vdly__top__DOT__m_fifo_buffer__DOT__write_pointer = 0;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__m_fifo_buffer__DOT__memory__v0;
    __Vdlyvdim0__top__DOT__m_fifo_buffer__DOT__memory__v0 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__m_fifo_buffer__DOT__memory__v0;
    __Vdlyvval__top__DOT__m_fifo_buffer__DOT__memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__m_fifo_buffer__DOT__memory__v0;
    __Vdlyvset__top__DOT__m_fifo_buffer__DOT__memory__v0 = 0;
    CData/*3:0*/ __Vdly__top__DOT__m_fifo_buffer__DOT__read_pointer;
    __Vdly__top__DOT__m_fifo_buffer__DOT__read_pointer = 0;
    CData/*5:0*/ __Vdly__top__DOT__m_fifo_buffer__DOT__count;
    __Vdly__top__DOT__m_fifo_buffer__DOT__count = 0;
    // Body
    __Vdly__top__DOT__m_fifo_buffer__DOT__read_pointer 
        = vlSelf->top__DOT__m_fifo_buffer__DOT__read_pointer;
    __Vdly__top__DOT__m_fifo_buffer__DOT__count = vlSelf->top__DOT__m_fifo_buffer__DOT__count;
    __Vdly__top__DOT__m_fifo_buffer__DOT__write_pointer 
        = vlSelf->top__DOT__m_fifo_buffer__DOT__write_pointer;
    __Vdlyvset__top__DOT__m_fifo_buffer__DOT__memory__v0 = 0U;
    if (vlSelf->rst) {
        __Vdly__top__DOT__m_fifo_buffer__DOT__count = 0U;
        __Vdly__top__DOT__m_fifo_buffer__DOT__write_pointer = 0U;
        __Vdly__top__DOT__m_fifo_buffer__DOT__read_pointer = 0U;
        vlSelf->data_out = 0U;
    } else {
        if ((2U == (((IData)(vlSelf->wr_en) << 1U) 
                    | (IData)(vlSelf->rd_en)))) {
            if ((1U & (~ (IData)(vlSelf->full)))) {
                __Vdly__top__DOT__m_fifo_buffer__DOT__count 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelf->top__DOT__m_fifo_buffer__DOT__count)));
            }
        } else if ((1U == (((IData)(vlSelf->wr_en) 
                            << 1U) | (IData)(vlSelf->rd_en)))) {
            if ((1U & (~ (IData)(vlSelf->empty)))) {
                __Vdly__top__DOT__m_fifo_buffer__DOT__count 
                    = (0x3fU & ((IData)(vlSelf->top__DOT__m_fifo_buffer__DOT__count) 
                                - (IData)(1U)));
            }
        } else {
            __Vdly__top__DOT__m_fifo_buffer__DOT__count 
                = vlSelf->top__DOT__m_fifo_buffer__DOT__count;
        }
        if ((1U & (~ (((IData)(vlSelf->rd_en) & (IData)(vlSelf->wr_en)) 
                      & ((IData)(vlSelf->full) | (IData)(vlSelf->empty)))))) {
            if (((IData)(vlSelf->wr_en) & (~ (IData)(vlSelf->full)))) {
                __Vdlyvval__top__DOT__m_fifo_buffer__DOT__memory__v0 
                    = vlSelf->data_in;
                __Vdlyvset__top__DOT__m_fifo_buffer__DOT__memory__v0 = 1U;
                __Vdlyvdim0__top__DOT__m_fifo_buffer__DOT__memory__v0 
                    = vlSelf->top__DOT__m_fifo_buffer__DOT__write_pointer;
                __Vdly__top__DOT__m_fifo_buffer__DOT__write_pointer 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__m_fifo_buffer__DOT__write_pointer)));
            }
        }
        if ((((IData)(vlSelf->rd_en) & (IData)(vlSelf->wr_en)) 
             & ((IData)(vlSelf->full) | (IData)(vlSelf->empty)))) {
            vlSelf->data_out = vlSelf->data_in;
        } else if ((1U & (~ ((IData)(vlSelf->wr_en) 
                             & (~ (IData)(vlSelf->full)))))) {
            if (((IData)(vlSelf->rd_en) & (~ (IData)(vlSelf->empty)))) {
                vlSelf->data_out = vlSelf->top__DOT__m_fifo_buffer__DOT__memory
                    [vlSelf->top__DOT__m_fifo_buffer__DOT__read_pointer];
                __Vdly__top__DOT__m_fifo_buffer__DOT__read_pointer 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__m_fifo_buffer__DOT__read_pointer)));
            }
        }
    }
    vlSelf->top__DOT__m_fifo_buffer__DOT__count = __Vdly__top__DOT__m_fifo_buffer__DOT__count;
    vlSelf->top__DOT__m_fifo_buffer__DOT__write_pointer 
        = __Vdly__top__DOT__m_fifo_buffer__DOT__write_pointer;
    vlSelf->top__DOT__m_fifo_buffer__DOT__read_pointer 
        = __Vdly__top__DOT__m_fifo_buffer__DOT__read_pointer;
    if (__Vdlyvset__top__DOT__m_fifo_buffer__DOT__memory__v0) {
        vlSelf->top__DOT__m_fifo_buffer__DOT__memory[__Vdlyvdim0__top__DOT__m_fifo_buffer__DOT__memory__v0] 
            = __Vdlyvval__top__DOT__m_fifo_buffer__DOT__memory__v0;
    }
    vlSelf->full = (0x10U == (IData)(vlSelf->top__DOT__m_fifo_buffer__DOT__count));
    vlSelf->empty = (0U == (IData)(vlSelf->top__DOT__m_fifo_buffer__DOT__count));
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
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/feipiao/Workplace/gitclone/uart_homework/other_tests/iverilog_test/vsrc/top.v", 1, "", "NBA region did not converge.");
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
                VL_FATAL_MT("/home/feipiao/Workplace/gitclone/uart_homework/other_tests/iverilog_test/vsrc/top.v", 1, "", "Active region did not converge.");
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
    if (VL_UNLIKELY((vlSelf->wr_en & 0xfeU))) {
        Verilated::overWidthError("wr_en");}
    if (VL_UNLIKELY((vlSelf->rd_en & 0xfeU))) {
        Verilated::overWidthError("rd_en");}
}
#endif  // VL_DEBUG
