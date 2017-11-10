CC=gcc -fno-omit-frame-pointer -fsanitize=address -fsanitize=leak -fsanitize=undefined -lncurses
CFLAGS= -g3 -W -Wall -Wextra -Werror

all: main

graph.o: graph.c graph.h

main: graph.o

clean:
	rm -rf main *.o
