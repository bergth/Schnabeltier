
#ifndef INDIVIDU_H
#define INDIVIDU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum defCouleurs {BLANC, BEIGE, GRIS, MARRON, NOIR};
enum defTeintes {CLAIR, FONCE};
enum defFourrure {epaisse, moyenne, courte} ;

#define NB_COULEURS 5
#define NB_FOURRURES 3

#define DEBUG 1 // mettre à 0 pour le code de production




typedef struct individu // niveau facile
{
    //caractéristiques
    float independance;
    float taille;
    float longueur_fourrure;
    int type_peau; //0: écailles, 1: plume, 2 :fourrure
    int regime; //0:herbivore, 1:carnivore, 2: omnivore
    int couleur;
    int teinte;
    int vitesse; //0:lent, 1: moyen, 2:rapide
    float predation;            //c'est un pourcentage -> vers 1 : predateur (haut de la chaine alimentaire, vers 0 prédaté, vers 0.5: les deux)
    float survie;               // pourcentage, il s'agit des chances de survie par rapport aux prédateurs --> c'est ce que l'on cherche dans la fonction
} Individu;

// Prototypes
typedef Individu * Espece;
Individu * creer_manuel_individu ();
Individu * creer_individu(Individu * pere, Individu * mere, unsigned int couleur) ;
void afficher_individu(Individu *);
int verif_individu(Individu *, int);
void test_individus();
Individu* nouvel_individus(int peau, int regime);
Individu* creer_individu_random();


#endif
