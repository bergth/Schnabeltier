#include "individus.h"
#include "utile.h"
//char * couleurs[NB_COULEURS] = {"Blanc", "Beige", "Gris", "Marron", "Noir"} ;
//int CouleurVersTeinte[NB_COULEURS] = {CLAIR, CLAIR, CLAIR, FONCE, FONCE} ;

Individu * creer_manuel_individu ();

Individu * creer_individu(Individu * pere, Individu * mere, unsigned int couleur) ;

void afficher_individu(Individu *);

int verif_individu(Individu *, int);

/*-------------------FONCTIONS-----------------------*/


Individu * creer_manuel_individu ()
{
    char * couleurs[NB_COULEURS] = {"Blanc", "Beige", "Gris", "Marron", "Noir"} ;

    int taille = 0;
    int couleur = 0;
    int type_de_peau;
    Individu * ind ;
    int i ;
    char stCoul[50];
    float pilositer;
    int regime;

    ind = malloc(sizeof(Individu));
    if (ind==NULL) return (NULL) ;

//    ind->mere=NULL ;
//    ind->pere=NULL;
//    ind->frere_g=NULL;

    printf("Créer un individu\n\n");

    do
    {
        printf("Saisir la taille de l'animal en cm \n\n");
        taille=saisie_float();

    } while( (taille<1));

    ind->taille = taille;

    couleur=NB_COULEURS ;

    while (couleur>=NB_COULEURS)
    {
        printf("Saisir la couleur de l'animal (");
        for (i=0;i<NB_COULEURS;i++) printf("%s ",couleurs[i]);
        printf(")\n");

        scanf("%s",stCoul);

        couleur=0 ;
        while ( (couleur<NB_COULEURS) && (strcmp(stCoul,couleurs[couleur])!=0)) couleur++ ;

    }

    ind->couleur=couleur ;

    fflush(stdin);

    //ind->teinte = CouleurVersTeinte[ind->couleur];


    do
    {
        printf("Saisir le type de peau : peaureux: 0, poilus: 1, cailleux: 2, plumeux: 3\n");
        type_de_peau = saisie_entier();

    } while ((type_de_peau<0) || (type_de_peau>=3));

    do
    {
        printf("Saisir le pourcentage de pilosite: \n");
        pilositer = saisie_float();

    } while ((pilositer<0));

    ind->pilosite = pilositer;

    do
    {

        printf("regime alimentaire: 1: carnivore, 2: herbivore, 3: omnivores\n");
        regime = saisie_entier();
    }while(regime<0 || regime>3);

    //ind->longueur_fourrure=fourrure;

 return(ind);
 }

 #define ERR_COULEUR 1
 #define ERR_TEINTE 2

 int verif_individu(Individu * ind, int debugMode) // vérifie que la structure est cohérente. mettre 1 dans debugMode pour afficher
 {
    int rc=0;

    if ((ind->couleur<0) || (ind->couleur>NB_COULEURS)) rc=1 ;
    if ((rc==1)&&(debugMode==1)) printf("ERREUR couleur\n");
    if (rc!=0) return(rc) ;

    // A completer avec tous les tests de cohérence de la strcuture Individu

    if((rc==0) && (debugMode==1)) printf("Structure individu OK\n");


 return(rc) ;
 }

void afficher_individu(Individu *ind)
{
    printf("A completer\n");
}

#define TAILLE 50


void test_individus()
{
    char nom[TAILLE];
   // int i;

    Individu * ancetre1 ;

    printf("Nom de l'espece:\n");
    scanf ("%s",nom);

    printf("1er individu de l'espèce %s \n", nom);
    ancetre1 = creer_manuel_individu() ;

    afficher_individu(ancetre1);

    verif_individu(ancetre1,DEBUG);

}

