
#ifndef INDIVIDU_H
#define INDIVIDU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define HERBIVORE 0
#define OMNIVORE  1
#define CARNIVORE 2

typedef struct destraits
{
    int cont;
    /* cas continu */
    float min;
    float max;
    /* cas discret */
    size_t n_dis;
    char** nom_dis;
    /* interactions */
    size_t nb_inter;
    size_t* inters;
    char* nom;
}Destraits;


typedef struct traits{
    int val;
    float coef;
}Traits;


typedef struct individu{
    int generation;
    float independance;
    Traits* trs;
}Individu;

// Prototypes


void afficher_individu(const Individu * ind, const Destraits* dtrs, size_t n);
Individu* creer_individu_random(const Destraits* dtrs, size_t n);
void liberer_individu(Individu** ind);
#endif
