#include "individus.h"
#include "utile.h"




Individu* creer_individu_random()
{
/*
    float independance;
    float taille;
    float longueur_fourrure;
    int couleur;
    int regime;
    int palmes;
    float predation;
    float taux_reprod;
*/

    Individu* new = malloc(sizeof(Individu));
    new->independance = (float)rand_ab(10,20) / 100;
    new->longueur_fourrure = (float)rand_ab(0,100)/(float)100;
    new->palmes = (float)rand_ab(0,100)/(float)100;
    //assert(new->longueur_fourrure >= 0.0001);
    new->taille = (float)rand_ab(0,100) / 100;
    new->regime = rand_ab(0,2);
    new->couleur = rand_ab(0,7);
    new->predation = (float)rand_ab(0,100) / 100;
    new->taux_reprod = new->predation = (float)rand_ab(0,100) / 100;
    return new;
}

void afficher_individu(Individu * ind)
{
    printf("[INDIVIDU]-----------------------------------\n");
    printf("Independance      : %f\n", ind->independance);
    printf("Longueur_fourrure : %f\n", ind->longueur_fourrure);
    printf("taille            : %f\n", ind->taille);
    printf("regime            : %d\n", ind->regime);
    printf("couleur           : %x\n", ind->couleur);
    printf("predation         : %f\n", ind->predation);
    printf("taux reprod       : %f\n", ind->taux_reprod);
    printf("[FIN INDIVIDU]-------------------------------\n");
}
