# # === Variables ===
# CC      := gcc
# CFLAGS  := -Wall -Wextra -Werror -std=c99
# SRC     := Linked_List_Manager.c
# OBJ     := $(SRC:.c=.o)
# TARGET  := bin/linkedlist_app

# # === Règles ===
# .PHONY: all clean fclean re

# all: $(TARGET)

# $(TARGET): $(OBJ) | bin
# 	$(CC) $(CFLAGS) $^ -o $@

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# bin:
# 	mkdir -p bin

# clean:
# 	rm -f *.o

# fclean: clean
# 	rm -f $(TARGET)

# re: fclean all

# === VARIABLES ===
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Iinclude
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
TARGET = $(BIN_DIR)/linkedlist_app

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
