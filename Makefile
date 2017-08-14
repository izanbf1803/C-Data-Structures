SOURCES = src/main.c src/vector.c

all:
	gcc -o main -Wall $(SOURCES)