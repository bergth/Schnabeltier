#include <stdio.h>
#include <stdlib.h>
#include "individus.h"
#include "graph.h"

typedef struct resultats{
	int n;
	Individu* moy;
	Individu* variance;
	Individu* equart;
} Resultats;

/*
typedef struct individu // niveau facile
{
    //caractéristiques
    float independance;
    float taille;
    int longueur_fourrure;
    int type_peau; //0: écailles, 1: plume, 2 :fourrure
    int regime; //0:herbivore, 1:carnivore, 2: omnivore
    int couleur;
    int teinte;
    int vitesse; //0:lent, 1: moyen, 2:rapide
    float predation;            //c'est un pourcentage -> vers 1 : predateur (haut de la chaine alimentaire, vers 0 prédaté, vers 0.5: les deux)
    float survie;               // pourcentage, il s'agit des chances de survie par rapport aux prédateurs --> c'est ce que l'on cherche dans la fonction
} Individu;

*/

typedef float (*getter)(const graph*); 



float resultats(const graph* g);
