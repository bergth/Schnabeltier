#ifndef CROISEMENT_H_INCLUDED
#define CROISEMENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "individus.h"

float aleatoire(void);
float croisement_continue(float trait1, float trait2, float coef);
Individu* croisement(const Individu* ind1,const Individu* ind2,const Destraits* trs, size_t n_trs, int gen);


#endif // CROISEMENT_H_INCLUDED
