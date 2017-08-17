SOURCES = src/main.c src/vector.c src/queue.c src/stack.c src/heap.c

all:
	gcc -o main -Wall $(SOURCES)