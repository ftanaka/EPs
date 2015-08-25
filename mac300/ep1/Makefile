CC = gcc
CFLAGS = -Wall -pedantic -ansi -g

DEPS = input.o

all = DEPS

input.o: input.c
	$(CC) $(CFLAGS) -c $^

.PHONY = clear
clear:
	rm -rf *.o
