CSRCS = ./csrc/main.cpp
VSRCS = $(shell find $(abspath ../../source) -name "*.v")
VSRCS += $(shell find $(abspath ./vsrc) -name "*.v")
# VSRCS += $(shell find $(abspath ../../testbench) -name "*.v")

TOPNAME = top

all:
	verilator -Wall ${VSRCS} ${CSRCS} --top-module ${TOPNAME} --cc --trace --exe --build --Mdir build

run:
	cd build && ./Vtop

sim:
	gtkwave ./build/wave.vcd
