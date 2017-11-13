#ifndef CROISEMENT_H_INCLUDED
#define CROISEMENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "individus.h"

int croisement_discret(int trait1, int trait2);
float aleatoire(void);
float croisement_continue(float trait1, float trait2, float coef);
void test_croisement(void);


#endif // CROISEMENT_H_INCLUDED
