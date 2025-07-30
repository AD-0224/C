# === VARIABLES ===
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Iinclude -D_POSIX_C_SOURCE=200809L
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
TARGET = $(BIN_DIR)/hashtableimplementation_app

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# === RÈGLES ===
all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

debug: CFLAGS += -g
debug: clean all
	gdb $(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all run debug clean
