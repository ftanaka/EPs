CC = gcc
CFLAGS = -Wall -pedantic -ansi -g

DEPS = input.o

all = $(DEPS) out

input.o: input.c
	$(CC) $(CFLAGS) -c $^

out: $(DEPS)
	$(CC) $(CFLAGS) $(DEPS) main.c

.PHONY = clear
clear:
	rm -rf *.o a.out*
