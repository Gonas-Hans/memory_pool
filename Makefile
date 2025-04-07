CC=gcc
CFLAGS=-Wall -Wextra -std=c11

all: memory_pool

memory_pool: main.o memory_pool.o
	$(CC) $(CFLAGS) -o memory_pool main.o memory_pool.o

main.o: main.c memory_pool.h
	$(CC) $(CFLAGS) -c main.c

memory_pool.o: memory_pool.c memory_pool.h
	$(CC) $(CFLAGS) -c memory_pool.c

clean:
	del *.o *.exe