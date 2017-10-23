#include "individus.h"
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
    int CouleurVersTeinte[NB_COULEURS] = {CLAIR, CLAIR, CLAIR, FONCE, FONCE} ;

    int taille = 0;
    int couleur = 0;
    int fourrure;
    Individu * ind ;
    int i ;
    char stCoul[50];

    ind = malloc(sizeof(Individu));
    if (ind==NULL) return (NULL) ;

//    ind->mere=NULL ;
//    ind->pere=NULL;
//    ind->frere_g=NULL;

    do
    {
        printf("Saisir la taille de l'animal en cm (entre 1cm et 10m (1000 cm)\n\n");

        scanf("%d", &taille);
    } while( (taille<1) || (taille>1000) );



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

    ind->teinte = CouleurVersTeinte[ind->couleur];


    do
    {
        printf("Saisir la longueur de la fourrure: �paisse: 0, moyenne: 1, courte: 2\n");
        scanf("%d", &fourrure);

    } while ((fourrure<0) || (fourrure>=NB_FOURRURES));

    ind->longueur_fourrure=fourrure;

 return(ind);
 }

 #define ERR_COULEUR 1
 #define ERR_TEINTE 2

 int verif_individu(Individu * ind, int debugMode) // v�rifie que la structure est coh�rente. mettre 1 dans debugMode pour afficher
 {
    int rc=0;

    if ((ind->couleur<0) || (ind->couleur>NB_COULEURS)) rc=1 ;
    if ((rc==1)&&(debugMode==1)) printf("ERREUR couleur\n");
    if (rc!=0) return(rc) ;

    // A completer avec tous les tests de coh�rence de la strcuture Individu

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

    printf("1er individu de l'esp�ce %s \n", nom);
    ancetre1 = creer_manuel_individu() ;

    afficher_individu(ancetre1);

    verif_individu(ancetre1,DEBUG);

}

