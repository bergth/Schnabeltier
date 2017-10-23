#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NB_COULEURS 5
#define NB_FOURRURES 3

#define DEBUG 1 // mettre � 0 pour le code de production

enum defCouleurs {BLANC, BEIGE, GRIS, MARRON, NOIR};
enum defTeintes {CLAIR, FONCE};
enum defFourrure {epaisse, moyenne, courte} ;

typedef struct individu // niveau facile
{

    //caract�ristiques
    unsigned int taille;
    unsigned int longueur_fourrure;
    unsigned int couleur;
    unsigned int teinte;
    //� complexifier

} Individu;

// Prototypes
typedef Individu * Espece;
Individu * creer_manuel_individu ();
Individu * creer_individu(Individu * pere, Individu * mere, unsigned int couleur) ;
void afficher_individu(Individu *);
int verif_individu(Individu *, int);
void test_individus();
