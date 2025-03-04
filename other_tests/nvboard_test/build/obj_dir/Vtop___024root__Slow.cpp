// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

// Parameter definitions for Vtop___024root
constexpr VlUnpacked<CData/*7:0*/, 16> Vtop___024root::top__DOT__my_uart_tester__DOT__my_lcd_double__DOT__high_lcd_single__DOT__hex_display;
constexpr VlUnpacked<CData/*7:0*/, 16> Vtop___024root::top__DOT__my_uart_tester__DOT__my_lcd_double__DOT__low_lcd_single__DOT__hex_display;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop___024root::~Vtop___024root() {
}
