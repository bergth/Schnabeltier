#ifndef CROISEMENT_H_INCLUDED
#define CROISEMENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "individus.h"

// retourne une valeur aléatoire
float aleatoire(void);
// créé un croisement continue de 2 trait
// trait1, trait2: les traits à croiser
// coef: indépendance du nouvel individu
float croisement_continue(float trait1, float trait2, float coef);
// créé un nouvel individu croisé à partir de ses deux parents
// ind1, ind2: les parents, 
//  n_trs: nombre de traits
// gen: génération du nouvel individu
Individu* croisement(const Individu* ind1,const Individu* ind2, size_t n_trs, int gen);

#endif // CROISEMENT_H_INCLUDED
