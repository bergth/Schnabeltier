#ifndef UTILE_H
#define UTILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// effectue une saisie sécurisée. Met le résultat dans un buffeur d'une taille donnée (taille)
void saisie_securisee(char* buf, size_t taille);
void vider_buffer();
// retourne la saisie d'un entier
int saisie_entier();
// retourne la saisie d'un float
float saisie_float();
// retourne un nombre définie aléatoirement entre a et b
int rand_ab(int a, int b);
// concataine str1 avec str2
void contat(char** str1, const char* str2);

#endif