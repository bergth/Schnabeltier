CC=gcc -fno-omit-frame-pointer -fsanitize=address -fsanitize=leak -fsanitize=undefined
CFLAGS= -W -Wall -Wextra -Werror

all: main

graph.o: graph.c graph.h
individus.o: individus.c individus.h
utile.o: utile.c utile.h
croisement.o: croisement.c croisement.h
environnement.o: environnement.c environnement.h
survie.o: survie.c survie.h

main: graph.o individus.o utile.o croisement.o environnement.o survie.o

clean:
	rm -rf main *.o
