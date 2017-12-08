#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include <string.h>



typedef struct ECaract
{
    int min;
    int max;
	float coef;
    char* nom;
}Ecaract;

typedef struct Environnement // A COMPLETER EN FONCTION DES ESPECES FONCTIONS DE CROISEMENT
{
    size_t n_caracts;
	Ecaract* caracts;
}Environnement;

/* Affiche sur stdout le milieu */
void Afficher_Milieu (const Environnement* env);
/* créé un environnement en fonction de temp et hum */
Environnement* creer_env(float temp, float hum, float eau, float pcar);
void Liberer_env(Environnement** env);
#endif