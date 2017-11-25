CC=gcc -fno-omit-frame-pointer -fsanitize=address -fsanitize=leak -fsanitize=undefined
CFLAGS= -g -lm -W -Wall -Wextra -Werror 
#-Wconversion

all: main

graph.o: graph.c graph.h
individus.o: individus.c individus.h
utile.o: utile.c utile.h
croisement.o: croisement.c croisement.h
environnement.o: environnement.c environnement.h
survie.o: survie.c survie.h
resultats.o: resultats.c resultats.h

main: graph.o individus.o utile.o croisement.o environnement.o survie.o resultats.o

clean:
	rm -rf main *.o
