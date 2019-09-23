CC=gcc
FLAGS=

EXAMPLE_DIR=src/examples
BIN_DIR=
INCLUDE=src/include

help:
	@echo Available commands:
	@echo example

example:
	$(CC) $(FLAGS) $(EXAMPLE_DIR)/test_simple_operations.c -I$(INCLUDE) -o $(BIN_DIR)/test_simple_operations 
	$(BIN_DIR)/test_simple_operations
   
