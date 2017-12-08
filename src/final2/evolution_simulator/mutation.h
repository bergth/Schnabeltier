#ifndef MUTATION_H_INCLUDED
#define MUTATION_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "individus.h"

void mutation(Individu* ind);
void test_mutation(void);
int mutation_discrete(int trait, float independance, int modulo);
float mutation_continue(float independance);

#endif // MUTATION_H_INCLUDED