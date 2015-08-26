CC = gcc
CFLAGS = -Wall -pedantic -ansi -g

DEPS = input.o
EXE = out

all = EXE

input.o: input.c
	$(CC) $(CFLAGS) -c $^

out: $(DEPS) main.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY = clear
clear:
	rm -rf *.o a.out*
