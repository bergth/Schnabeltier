#include <stdio.h>
#include <stdlib.h>
#include"croisement.h"
#include "utile.h"

int croisement_discret(int trait1, int trait2)
{
    int dom, rec, prob;

    if((trait1 % 2) !=  (trait2 % 2))
    {

        if(trait1 % 2 == 0 && trait2 % 2 != 0)
        {
            dom = trait1;
            rec = trait2;

        }


        else if(trait2 % 2 == 0 && trait1 % 2 !=0)
        {
            dom = trait2;
            rec = trait1;

        }

        prob = rand()%100;



        if(prob > 75)
            return rec;

        else
            return dom;

    }

    else if((trait1 %2 ) == (trait2 % 2))
    {
        if(trait1 >= trait2)
        {
            dom = trait1;
            rec = trait2;
        }

        else if(trait1 < trait2)
        {
            dom = trait2;
            rec = trait1;
        }

        prob = rand()%100;

        if(prob>95)
            return rec;

        else
            return dom;

    }

    return -1;

}

float aleatoire(void)
{
    return (float)rand_ab(75,120);
}

float croisement_continue(float trait1, float trait2, float coef)
{
    return (trait1 + trait2)/2;
    float resultat, t1, t2, coefmod;
    int random;
    t1 = (trait1 * aleatoire())/100;
    t2 = (trait2 * aleatoire())/100;
    //printf("[%f][%f]\n", trait1, trait2);
    resultat=(t1+t2)/2;
    return resultat;
    if(resultat>coef)
    {
        random = rand() % 2;
        if(random == 0)
            coefmod = (-1)*coef;
        else
            coefmod = coef;
     }
     else
        coefmod = 0;

    resultat = ((t1+t2)/2) + coefmod;
    //printf("res: [%f]\n", resultat);
   /* if(resultat <= 0.05)
    {
        printf("[%f][%f][%f]\n", resultat, trait1, trait2);
        exit(EXIT_FAILURE);
    } */
    //assert(trait1 >= 0.0001  && trait2 >=  0.0001);
    //assert(resultat >= 0.0001);
    return resultat;
}

Individu* croisement(const Individu* ind1,const Individu* ind2)
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
    //printf("[%f][%f]\n", ind1->longueur_fourrure, ind2->longueur_fourrure);
    //assert(ind1->longueur_fourrure >= 0.0001 && ind2->longueur_fourrure >= 0.0001);
    Individu* enfant = NULL;

    enfant = malloc(sizeof(Individu));

    enfant->independance = ind1->independance;
    enfant->taille = 0; // croisement_continue(ind1->taille, ind2->taille, enfant->independance);
    enfant->longueur_fourrure = croisement_continue(ind1->longueur_fourrure, ind2->longueur_fourrure,enfant->independance);
    enfant->couleur = 0; //croisement_discret(ind1->couleur, ind2->couleur);
    enfant->regime = 0; //croisement_discret(ind1->regime,ind2->regime);
    enfant->palmes = croisement_continue(ind1->palmes, ind2->palmes, enfant->independance);
    enfant->predation = 0; //croisement_continue(ind1->predation, ind2->predation, enfant->independance);
    enfant->taux_reprod = 0;// croisement_continue(ind1->taux_reprod, ind2->taux_reprod, enfant->independance);

    return enfant;
}

