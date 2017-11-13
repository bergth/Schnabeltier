CC=gcc -fno-omit-frame-pointer -fsanitize=address -fsanitize=leak -fsanitize=undefined -lncurses
CFLAGS= -g3 -W -Wall -Wextra -Werror

all: main

graph.o: graph.c graph.h
individus.o: individus.c individus.h
croisement.o: croisement.c croisement.h
utile.o: utile.c utile.h

main: graph.o individus.o croisement.o utile.o

clean:
	rm -rf main *.o
