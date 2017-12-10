#ifndef RESULTATS_H
#define RESULTATS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "individus.h"
#include "graph.h"

// structure contenant les statistiques de résultat
typedef struct stats{
	int n;
	float moy;
	float variance;
	float equart;
    char* nom;
} Stats;

// tableau de statistiques de résultat
typedef struct resultats{
	size_t n;
    Stats* sts;
    char** noms;
} Resultats;

// créé les stats pour un trait
// g: le graphe
// trait: index du trait à traiter
Stats get_stats(const graph* g, size_t trait);

// créé la liste des résultats
// g: le graphe
Resultats* get_resultat(const graph* g);

// affiche les résultat (r) sur stdout
void print_resultat(const Resultats* r);

// libère les résultats
void free_resultats(Resultats** r);

#endif