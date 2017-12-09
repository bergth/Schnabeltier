#ifndef UTILE_H
#define UTILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void saisie_securisee(char* buf, size_t taille);
void vider_buffer();
int saisie_entier();
float saisie_float();
int rand_ab(int a, int b);
void contat(char** str1, const char* str2);


#endif