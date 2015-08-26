CC = gcc
CFLAGS = -Wall -pedantic -ansi -g

DEPS = input.o cholesky.o

all = exe

exe: $(DEPS) main.c
	$(CC) $(CFLAGS) $^

input.o: input.c
	$(CC) $(CFLAGS) -c $^

cholesky.o: cholesky.c
	$(CC) $(CFLAGS) -c $^

.PHONY = clear
clear:
	rm -rf *.o a.out*
