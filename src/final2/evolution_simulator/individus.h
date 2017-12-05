
#ifndef INDIVIDU_H
#define INDIVIDU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define HERBIVORE 0
#define OMNIVORE  1
#define CARNIVORE 2


typedef struct individu
{
    float independance;
    float taille;
    float longueur_fourrure;
    int couleur;
    int regime;
    float palmes;
    float predation;
    float taux_reprod;
} Individu;

// Prototypes


void afficher_individu(Individu *);
Individu* creer_individu_random();


#endif
