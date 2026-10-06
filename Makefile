CC := cc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic
BIN_DIR := bin

TARGETS := \
	$(BIN_DIR)/ascii_binary \
	$(BIN_DIR)/ascii_binary_alternate \
	$(BIN_DIR)/dynamic_memory_swap \
	$(BIN_DIR)/process_exec \
	$(BIN_DIR)/process_zombie \
	$(BIN_DIR)/process_orphan \
	$(BIN_DIR)/tcp_client \
	$(BIN_DIR)/tcp_server

.PHONY: all check-shell clean

all: $(TARGETS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/ascii_binary: rec01-c-basics/ascii_binary.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(BIN_DIR)/ascii_binary_alternate: rec01-c-basics/ascii_binary_alternate.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(BIN_DIR)/dynamic_memory_swap: rec02-dynamic-memory/rec02.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(BIN_DIR)/process_exec: rec08-processes/rec08A.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(BIN_DIR)/process_zombie: rec08-processes/rec08B.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(BIN_DIR)/process_orphan: rec08-processes/rec08C.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(BIN_DIR)/tcp_client: rec11-networking/rec11cli.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(BIN_DIR)/tcp_server: rec11-networking/rec11svr.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

check-shell:
	bash -n rec06-shell-scripting/rec06A.sh
	bash -n rec06-shell-scripting/rec06B.sh
	bash -n rec06-shell-scripting/rec06C.sh
	bash -n rec07-bash-arrays/rec07.sh

clean:
	rm -rf $(BIN_DIR)
