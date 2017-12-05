#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

typedef struct Environnement // A COMPLETER EN FONCTION DES ESPECES FONCTIONS DE CROISEMENT
{
	float temp; // temperature
 	float hum;  // humidité
	float eau;  // % de présence d'eau
	int cdom;   // couleur dominante
	float pveg; // pourcentage végétation
	float pcar; // pourcentage carnivores
}Environnement;

/* Affiche sur stdout le milieu */
void Afficher_Milieu (Environnement *milieu);
/* créé un environnement en fonction de temp et hum */
Environnement* creer_env(float temp, float hum, float eau, float pcar);

#endif