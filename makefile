# Makefile

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Targets
all: main

main: main.c
	$(CC) $(CFLAGS) -g -o main main.c -lm

clean:
	rm -f main

.PHONY: all clean