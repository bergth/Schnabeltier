#ifndef SURVIE_H
#define SURVIE_H


#include "individus.h"

/*typedef struct environnement // A COMPLETER EN FONCTION DES ESPECES FONCTIONS DE CROISEMENT
{
	int type;														// 0 : FORET ; 1 : JUNGLE ; 2 : MONTAGNE ; 3 : SAVANE ; 4 : DESERT ; 5 : PLAINE ; 6 : BANQUISE ; 7 : PERSONNALISE
	int temperature; 												// 0 : froid ; 1 : ambiant ; 2 : chaud ; 3 : aride ; 4 : negatif
	int climat; 													// 0 : tropical humide ; 1 : tropical sec ; 2 : tempéré ; 3 : polaire
	int relief; 													// 0 : plat ; 1 : présence relief (montagne, plateau)
	int quantite_ressource; 										// 0 : petite ; 1 : moyenne ; 2 : grande
	int quantite_eau;
	float pourcentage_predateur;											// 0 : aucune ; 1 : petite ; 2 : moyenne ; 3 : grande
}Environnement;*/

float survie_predateur(Environnement * environnement, Individu * ind);
int pourcentage_survie_foret( Individu ind);
int pourcentage_survie_jungle( Individu ind);
int pourcentage_survie_jungle( Individu ind);
int pourcentage_survie_montagne( Individu ind);
int pourcentage_survie_savane( Individu ind);
float pourcentage_survie_desert( Individu ind);
int pourcentage_survie_pleine( Individu ind);
float pourcentage_survie_banquise( Individu ind);
int survie_globale(const Individu* ind, const Environnement* env);

#endif