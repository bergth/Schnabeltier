#ifndef RESULTATS_H
#define RESULTATS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "individus.h"
#include "graph.h"

typedef struct stats{
	int n;
	float moy;
	float variance;
	float equart;
    char* nom;
} Stats;


typedef struct resultats{
	size_t n;
    Stats* sts;
    char** noms;
} Resultats;


Stats get_stats(const graph* g, size_t trait);
Resultats* get_resultat(const graph* g);
void print_resultat(const Resultats* r);
void free_resultats(Resultats** r);

#endif