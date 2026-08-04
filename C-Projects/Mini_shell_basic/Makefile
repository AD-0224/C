# === VARIABLES ===
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Iinclude -D_POSIX_C_SOURCE=200809L
# Compiler flags:
# -Wall          → enable basic warnings
# -Wextra        → enable extra warnings
# -Werror        → treat all warnings as errors
# -std=c99       → use the C99 standard
# -Iinclude      → add "include" directory to the header search path
# -D_POSIX_C_SOURCE=200809L → enable modern POSIX functions (e.g., getline)

SRC_DIR = src
# Directory containing .c source files

BUILD_DIR = build
# Directory where object files (.o) will be stored

BIN_DIR = bin
# Directory where the final executable will be stored

TARGET = $(BIN_DIR)/minishellbasic_app
# Name and location of the final executable


# === SOURCES AND OBJECTS ===
SRCS = $(wildcard $(SRC_DIR)/*.c)
# Automatically finds all .c files inside src/

OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
# Converts each "src/file.c" into "build/file.o"


# === RULES ===
all: $(TARGET)
# Default rule: when you type "make", build the target executable

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
# Create the bin/ directory if it doesn't exist
	$(CC) $(CFLAGS) $^ -o $@
# Link all object files ($^) into the final executable ($@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
# Create the build/ directory if it doesn't exist
	$(CC) $(CFLAGS) -c $< -o $@
# Compile each source file ($<) into an object file ($@)

run: all
	./$(TARGET)
# Compile (if needed) and then run the program

debug: CFLAGS += -g
debug: clean all
# Add debugging symbols (-g), clean, and recompile
	gdb $(TARGET)
# Launch gdb with the executable

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
# Remove all build artifacts (object files and executables)

re:
	$(MAKE) clean
	$(MAKE) all
.PHONY: all run debug clean re
# These are not real files but "phony" targets (commands)