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
} Stats;


typedef struct resultats{
	Stats* taille;
    Stats* longueur_fourrure;
    Stats* type_peau; 
    Stats* regime; 
    Stats* couleur;
    Stats* teinte;
    Stats* vitesse;
} Resultats;



typedef float (*getter)(const graph*, size_t); 

float get_taille(const graph* g, size_t i);
float get_longueur_fourrure(const graph* g, size_t i);
float get_type_peau(const graph* g, size_t i);
float get_regime(const graph* g, size_t i);
float get_couleur(const graph* g, size_t i);
float get_teinte(const graph* g, size_t i);
float get_vitesse(const graph* g, size_t i);

Stats* get_stats(const graph* g, getter get);
Resultats* get_resultat(const graph* g);
void print_resultat(const Resultats* r);
void free_resultats(Resultats** r);

#endif