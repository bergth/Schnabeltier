CC=gcc -fno-omit-frame-pointer -fsanitize=address -fsanitize=leak -fsanitize=undefined
CFLAGS= -W -Wall -Wextra -Werror

all: main

arbre.o: arbre.c arbre.h
file.o: file.c file.h
individus.o: individus.c individus.h
utile.o: utile.c utile.h
croisement.o: croisement.c croisement.h

main: arbre.o file.o individus.o utile.o croisement.o

clean:
	rm -rf main *.o
