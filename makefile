# Makefile

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra 

# Targets
all: main

main: main.c
	$(CC) $(CFLAGS) -g -o main main.c -lm

test: test.c
	$(CC) $(CFLAGS) -g -o test test.c

clean:
	rm -f main

.PHONY: all clean