#ifndef SURVIE_H
#define SURVIE_H
#include <stdio.h>
#include <math.h>

#include "individus.h"

#define TAUX_SURVIE 0.2

float survie_continue(float c_ind, float c_env);
int survie_globale(const Individu* ind, const Destraits* trs, size_t n_trs, const Environnement* env, int gen);
#endif