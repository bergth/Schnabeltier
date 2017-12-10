#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include <string.h>


// caractère de l'environnement
typedef struct ECaract
{
	float coef;
    char* nom;
}Ecaract;

// Structure de l'environnement (liste de caractères)
typedef struct Environnement 
{
    size_t n_caracts;
	Ecaract* caracts;
}Environnement;

/* Affiche sur stdout le milieu */
// env: l'environnement
void Afficher_Milieu (const Environnement* env);

/* créé un environnement: valeurs entre 0 et 1 (float)*/
// temp: température
// hum: humidité
// eau: pourcentage d'eau sur le terrain
// pcar: pourcentage de carnivores
Environnement* creer_env(float temp, float hum, float eau, float pcar);
// libère un environnement
void Liberer_env(Environnement** env);
#endif