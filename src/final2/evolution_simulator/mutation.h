#ifndef MUTATION_H_INCLUDED
#define MUTATION_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "individus.h"

void mutation(Individu* ind, const Destraits* trs, size_t n);
float mutation_continue(float independance);

#endif // MUTATION_H_INCLUDED