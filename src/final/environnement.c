#include <stdio.h>
#include <stdlib.h>
#include "environnement.h"


void Affectation_Type (Environnement *milieu, int choix_du_type)
{
    if(choix_du_type == 1) // Desert
    {
        milieu->temperature = 40;
        milieu->relief = 0;
        milieu->quantite_eau = 20;
        milieu->quantite_ressource = 30;
    }
    if(choix_du_type == 2) // Montagne
    {
        milieu->temperature = 1;
        milieu->relief = 1;
        milieu->quantite_eau = 30;
        milieu->quantite_ressource = 50;
    }
    if(choix_du_type == 3) // Foret
    {
        milieu->temperature = -2;
        milieu->relief = 0;
        milieu->quantite_eau = 50;
        milieu->quantite_ressource = 75;
    }
    if(choix_du_type == 4) // Banquise
    {
        milieu->temperature = -33;
        milieu->relief = 1;
        milieu->quantite_eau = 75;
        milieu->quantite_ressource = 65;
    }
    if(choix_du_type == 5) // Savane
    {
        milieu->temperature = 25;
        milieu->relief = 0;
        milieu->quantite_eau = 45;
        milieu->quantite_ressource = 60;
    }
    if(choix_du_type == 6) // Jungle
    {
        milieu->temperature = 25;
        milieu->relief = 0;
        milieu->quantite_eau = 55;
        milieu->quantite_ressource = 70;
    }
    if(choix_du_type == 7) // Plaine
    {
        milieu->temperature = 13;
        milieu->relief = 0;
        milieu->quantite_eau = 50;
        milieu->quantite_ressource = 80;
    }
}

/* Fonction qui permet de créer un Milieu */

Environnement* Creer_Milieu ()
{
    Environnement *milieu = malloc(sizeof(Environnement));

    printf("Veuillez saisir le type d'environnement souhaite :\n");
    printf("1/ Desert\n");
    printf("2/ Montagne\n");
    printf("3/ Foret\n");
    printf("4/ Banquise\n");
    printf("5/ Savane\n");
    printf("6/ Jungle\n");
    printf("7/ Plaine\n");
    printf("8/ Personnalise\nChoix :");
    scanf("%d", &milieu->type);

    Affectation_Type (milieu, milieu->type);

    return milieu;
}

/* Fonction qui permet d'afficher les caractéristiques d'un Milieu */

void Afficher_Milieu (Environnement *milieu)
{
    printf("Le milieu defini est le suivant :\n\n");
    if (milieu->type == 1) printf("Le type de milieu selectionne : Desert\n");
    if (milieu->type == 2) printf("Le type de milieu selectionne : Montagne\n");
    if (milieu->type == 3) printf("Le type de milieu selectionne : Foret\n");
    if (milieu->type == 4) printf("Le type de milieu selectionne : Banquise\n");
    if (milieu->type == 5) printf("Le type de milieu selectionne : Savane\n");
    if (milieu->type == 6) printf("Le type de milieu selectionne : Jungle\n");
    if (milieu->type == 7) printf("Le type de milieu selectionne : Plaine\n");
    if (milieu->type == 8) printf("Le type de milieu selectionne : Personnalise\n");
    printf("La temperature est de %d degres\n", milieu->temperature);
    if (milieu->relief == 0) printf("Le milieu ne presente pas de relief\n");
    else printf("Le milieu presente un relief\n");
    printf("Le pourcentage des ressources disponible est : %d\n", milieu->quantite_ressource);
    printf("Le pourcentage de la quantite en eau est : %d\n", milieu->quantite_eau);
}

