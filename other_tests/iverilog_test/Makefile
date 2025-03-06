INIT_FILE := ./build/init.txt
LOOP_FILE := ./build/loop.txt
TOP_FILE := ./build/top.v
MAIN_TEMP := ./build/main_temp.cpp
MAIN_SRC := ./test_csrc/main.cpp
VSRC_DIR := ../../source
TESTS_CPP_DIR := test_csrc
TOPNAME = top

VSRCS = $(shell find $(abspath ../../source) -name "*.v")
VSRCS += $(TOP_FILE)
TEST_CPP_FILE := $(shell find $(TESTS_CPP_DIR) -type f -name "$(target).cpp" 2>/dev/null)
TEST_MODULE_FILE := $(shell find $(VSRC_DIR) -type f -name "$(target).v" 2>/dev/null)

init: 
	@mkdir -p build

$(TOP_FILE): init
	python ./extract_top.py $(TEST_MODULE_FILE) $(TOP_FILE)

# 处理 init.txt（提取全局变量）
$(INIT_FILE): $(TEST_CPP_FILE) init
	@echo "[INFO] Extracting global variable definitions into $(INIT_FILE)..."
	@sed -n '/\/\* begin of related init data \*\//,/\/\* end of related init data \*\//p' $(TEST_CPP_FILE) | \
		sed '1d;$$d' > $(INIT_FILE)

# 处理 loop.txt（提取 simulate_loop 内容，但去掉函数签名）
$(LOOP_FILE): $(TEST_CPP_FILE) init
	@echo "[INFO] Extracting simulate_loop function body into $(LOOP_FILE)..."
	@awk '/void simulate_loop/,/^}/ {print}' $(TEST_CPP_FILE) | sed '1d;/^{/d;/^}/d' > $(LOOP_FILE)

# 处理 main_temp.cpp（替换 sim_context.temp 和 sim_loop.temp）
$(MAIN_TEMP): $(MAIN_SRC) $(INIT_FILE) $(LOOP_FILE)
	@echo "[INFO] Generating $(MAIN_TEMP) by replacing placeholders..."
	@awk 'BEGIN { \
		    init_file = "./build/init.txt"; \
		    loop_file = "./build/loop.txt"; \
		} \
		{ \
		    if ($0 /#include[[:space:]]*"sim_context.temp"/) { \
		     while ((getline line < init_file) > 0) print line; \
		     close(init_file); \
		     next; \
		    } \
		    if ($0 /#include[[:space:]]*"sim_loop.temp"/) { \
		     while ((getline line < loop_file) > 0) print line; \
		     close(loop_file); \
		     next; \
		    } \
		    print; \
		}' $(MAIN_SRC) > $(MAIN_TEMP)


all: $(INIT_FILE) $(LOOP_FILE) $(MAIN_TEMP) $(TOP_FILE)
	verilator -Wall ${VSRCS} ${MAIN_TEMP} --top-module ${TOPNAME} --cc --trace --exe --build --Mdir build

run: all
	@cd build && ./Vtop

sim:
	@gtkwave ./build/wave.vcd

clean:
	@rm -rf $(INIT_FILE) $(LOOP_FILE) $(MAIN_TEMP)

# 打印文件路径
find:
	@echo "[INFO] Check find file: $(TARGET)"
	@if [ -n "$(TEST_CPP_FILE)" ]; then echo "[SUCCESS] C++: $(TEST_CPP_FILE)"; else echo "[FAILED] $(TARGET).cpp not found"; fi
	@if [ -n "$(TEST_MODULE_FILE)" ]; then echo "[SUCCESS] Verilog: $(TEST_MODULE_FILE)"; else echo "[FAILED] $(TARGET).v not found"; fi
