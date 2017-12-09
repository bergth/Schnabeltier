CC=gcc -lsqlite3 -fno-omit-frame-pointer -fsanitize=address -fsanitize=leak -fsanitize=undefined
CFLAGS= -g -lm -W -Wall -Wextra -Werror -Wconversion

all: main

graph.o: graph.c graph.h
individus.o: individus.c individus.h
utile.o: utile.c utile.h
croisement.o: croisement.c croisement.h
environnement.o: environnement.c environnement.h
survie.o: survie.c survie.h
mutation.o: mutation.c mutation.h
resultats.o: resultats.c resultats.h
dbase.o: dbase.c dbase.h

main: environnement.o individus.o utile.o survie.o croisement.o graph.o resultats.o mutation.o dbase.o

notebook: main vogelbekdier.py example.ipynb
	mkdir notebook
	cp main notebook/
	cp vogelbekdier.py notebook/
	cp example.ipynb notebook/
	jupyter-notebook --no-browser notebook/example.ipynb

clean:
	rm -rf main *.o *.db
	rm -rf notebook