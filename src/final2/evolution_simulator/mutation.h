#ifndef MUTATION_H_INCLUDED
#define MUTATION_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "individus.h"

// effectue la mutation sur un individu
// ind: l'individu
// n: nombre de traits
void mutation(Individu* ind, size_t n);

// calcule une nouvelle valeurs a ajouter pour la mutation
// independance: l'indépendance de l'individu
// retourne une nouvelle valeurs a ajouter pour la mutation
float mutation_continue(float independance);

#endif // MUTATION_H_INCLUDED