#ifndef SURVIE_H
#define SURVIE_H
#include <stdio.h>
#include <math.h>

#include "individus.h"

// calcul le pourcentage de survie entre un trait d'un individu et la caractéristique d'un environnement
// c_ind: trait individu
// c_env: caractéristique environnement
// retourne la chance de survie (entre 0 et 1)
float survie_continue(float c_ind, float c_env);

// détermine si un individu meurs ou non en fonction de ses traits et de l'environnement
// ind: l'individu à traiter
// trs: description des traits
// n: nombre de traits
// env: l'environnement
// gen: la génération de l'individu
// retourne un booléen (0: survie, 1: meurs)
int survie_globale(const Individu* ind, const Destraits* trs, size_t n_trs, const Environnement* env, size_t gen);
#endif