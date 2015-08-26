CC = gcc
CFLAGS = -Wall -pedantic -ansi -g

DEPS = input.o

all = out

input.o: input.c
	$(CC) $(CFLAGS) -c $^

out: $(DEPS) main.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY = clear
clear:
	rm -rf *.o a.out*
