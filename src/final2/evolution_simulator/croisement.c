#include <stdio.h>
#include <stdlib.h>
#include"croisement.h"
#include "utile.h"

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
    return resultat;
}

Individu* croisement(const Individu* ind1,const Individu* ind2,const Destraits* trs, size_t n_trs, int gen)
{
    Individu* enfant = calloc(sizeof(Individu),1);
    enfant->generation = gen;
    enfant->independance = ind1->independance;
    enfant->trs = calloc(sizeof(Traits),n_trs);
    for(size_t i = 0; i < n_trs; i++)
    {
        if(1 == trs[i].cont)
        {
            enfant->trs[i].coef = croisement_continue(ind1->trs[i].coef, ind2->trs[i].coef, enfant->independance);
        }
        else
        {
            assert(0);
        }
    }
    return enfant;
}

