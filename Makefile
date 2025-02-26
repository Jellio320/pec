SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

BINS := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%, $(wildcard $(SRC_DIR)/*.c))

CC = cc
CFLAGS = -std=c89 -O2 -g -Wall -Wextra

LD = $(CC)

.PHONY: all clean
.PRECIOUS: $(OBJ_DIR)/%.o

all: $(BINS)

$(BIN_DIR)/%: $(OBJ_DIR)/%.o | $(BIN_DIR)
	$(LD) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BIN_DIR) $(OBJ_DIR):
	@mkdir -p $@

clean:
	$(RM) $(BINS) $(OBJ_DIR)/*.o