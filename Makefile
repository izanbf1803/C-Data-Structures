SOURCES = src/main.c src/cvector.c

all:
	gcc -o main -Wall $(SOURCES)