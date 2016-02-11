# Sample Make file for C programs.

CC      = gcc
INC_DIR = header
SRC_DIR = source
OBJ_DIR = object
CFLAGS  = -c -Wall -I.

# If the object directory is not present, create it.
dummy := $(shell test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR))

SRCS = $(SRC_DIR)/utils.c $(SRC_DIR)/main.c 

OBJS = $(OBJ_DIR)/utils.o $(OBJ_DIR)/main.o
# Note: The above will soon get unwieldy.
# The wildcard and patsubt commands will come to your rescue.

DEPS = $(INC_DIR)/utils.h
# Note: The above will soon get unwieldy.
# You will soon want to use an automatic dependency generator.



all: $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: $(DEPS)


clean:
	-rm -rf $(OBJ_DIR)
