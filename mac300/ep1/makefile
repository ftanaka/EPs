CC = gcc
CFLAGS = -Wall -pedantic -ansi -g

DEPS = input.o

all = exe

exe: $(DEPS) main.c
	$(CC) $(CFLAGS) $^

input.o: input.c
	$(CC) $(CFLAGS) -c $^

.PHONY = clear
clear:
	rm -rf *.o a.out*
