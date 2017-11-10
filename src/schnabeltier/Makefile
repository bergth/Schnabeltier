CC=gcc -fsanitize=address -fsanitize=leak -fsanitize=undefined -lncurses
CFLAGS= -W -Wall -Wextra -Werror

all: main

arbre.o: arbre.c arbre.h
file.o: file.c file.h
individus.o: individus.c individus.h
utile.o: utile.c utile.h

main: arbre.o file.o individus.o utile.o

clean:
	rm -rf main *.o