#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

typedef struct autre_especes
{
    int carnivores ;
    int herbivores;
    int omnivores;
} Autre_especes;
typedef struct environnement // A COMPLETER EN FONCTION DES ESPECES FONCTIONS DE CROISEMENT
{
	int type;														// 0 : FORET ; 1 : JUNGLE ; 2 : MONTAGNE ; 3 : SAVANE ; 4 : DESERT ; 5 : PLAINE ; 6 : BANQUISE ; 7 : PERSONNALISE
	int temperature; 												// 0 : froid ; 1 : ambiant ; 2 : chaud ; 3 : aride ; 4 : negatif
	int climat; 													// 0 : tropical humide ; 1 : tropical sec ; 2 : tempéré ; 3 : polaire
	int relief; 													// 0 : plat ; 1 : présence relief (montagne, plateau)
	int quantite_ressource; 										// 0 : petite ; 1 : moyenne ; 2 : grande
	int quantite_eau;
	float pourcentage_predateur;											// 0 : aucune ; 1 : petite ; 2 : moyenne ; 3 : grande
}Environnement;

#define DESERT 1 
#define MONTAGNE 2 
#define FORET 3 
#define BANQUISE 4 
#define SAVANE 5 
#define JUNGLE 6 
#define PLAINE 7 


void Affectation_Type (Environnement *milieu, int choix_du_type);
Environnement* Creer_Milieu ();
void Afficher_Milieu (Environnement *milieu);

#endif