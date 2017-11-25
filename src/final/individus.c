#include "individus.h"
#include "utile.h"

const char * couleurs[NB_COULEURS] = {"Blanc", "Beige", "Gris", "Marron", "Noir"} ;
const int CouleurVersTeinte[NB_COULEURS] = {CLAIR, CLAIR, CLAIR, FONCE, FONCE} ;



Individu * creer_manuel_individu ()
{
    int taille = 0;
    int couleur = 0;
    int fourrure;
    int peau;
    int regime;
    int vitesse;
    float predation;
    Individu * ind ;
    int i ;
    char stCoul[50];

    ind = malloc(sizeof(Individu));
    if (ind==NULL) return (NULL) ;

    printf("Créer un individu\n\n");

    do
    {
        printf("Saisir la taille de l'animal en cm (entre 1cm et 10m (1000 cm)\n\n");

        scanf("%d", &taille);
    }
    while( (taille<1) || (taille>1000) );



    couleur=NB_COULEURS ;

    while (couleur>=NB_COULEURS)
    {
        printf("Saisir la couleur de l'animal (");
        for (i=0; i<NB_COULEURS; i++) printf("%s ",couleurs[i]);
        printf(")\n");

        scanf("%s",stCoul);

        couleur=0 ;
        while ( (couleur<NB_COULEURS) && (strcmp(stCoul,couleurs[couleur])!=0)) couleur++ ;

    }

    ind->couleur=couleur ;

    ind->teinte = CouleurVersTeinte[ind->couleur];


    do
    {
        printf("Saisir la longueur de la fourrure: épaisse: 0, moyenne: 1, courte: 2\n");
        scanf("%d", &fourrure);

    }
    while ((fourrure<0) || (fourrure>=NB_FOURRURES));

    ind->longueur_fourrure=fourrure;

    do
    {
        printf("Saisir le type de peau: 0: écailles, 1: plume, 2 :fourrure\n");
        scanf("%d", &peau);


    }
    while ((peau != 0) && (peau != 1) && (peau != 2));

    ind->type_peau = peau;

    do
    {
        printf("Saisir le régime : 0:herbivore, 1:carnivore, 2: omnivore\n");
        scanf("%d", &regime);

    }
    while ((regime != 0) && (regime != 1) && (regime != 2));
ind->regime = regime;

do
    {
        printf("Saisir la vitesse de l'animal : //0:lent, 1: moyen, 2:rapide\n");
        scanf("%d", &vitesse);

    }
    while ((vitesse != 0) && (vitesse != 1) && (vitesse != 2));

    ind->vitesse = vitesse;

      do
    {
        printf("Saisir la place de l'animal dans la chaine alimentaire (si predateur, ça tend vers 1, si proie, ça tend vers 0)\n");
        scanf("%e", &predation);

    }
    while ((predation<0) || (predation>1));
    ind->predation = predation;


    return(ind);
}


 #define ERR_COULEUR 1
 #define ERR_TEINTE 2

 int verif_individu(Individu * ind, int debugMode) // vérifie que la structure est cohérente. mettre 1 dans debugMode pour afficher
 {
    int rc=0;

    if (/*(ind->couleur<0) || */ (ind->couleur>NB_COULEURS)) rc=1 ;
    if ((rc==1)&&(debugMode==1)) printf("ERREUR couleur\n");
    if (rc!=0) return(rc) ;

    // A completer avec tous les tests de cohérence de la strcuture Individu

    if((rc==0) && (debugMode==1)) printf("Structure individu OK\n");


 return(rc) ;
 }

void afficher_individu(Individu *ind)
{
    if(ind == NULL)
    {
        printf("Individu [NULL]\n");
    }
    else
    {
       	char* peau[4] = {"peaureux","poilus","ecailleux","plumeux"};
        char* couleurs[NB_COULEURS] = {"Blanc", "Beige", "Gris", "Marron", "Noir"} ;
        char* regime[3]={"carnivore", "herbivore", "omnivore"};

        printf("taille: %f\n",ind->taille);

        printf("peau: %s\n",peau[ind->type_peau]);

       // printf("taux de pilosite: %f\n",ind->pilosite);

        printf("couleur de peaux: %s\n",couleurs[ind->couleur]);

        printf("regime alimentaire: %s\n",regime[ind->regime]);
    }
}

Individu* nouvel_individus(int peau, int regime)
{
    int couleur;
    //float pilositer, 
    float taille;
    Individu* nouv = NULL;

    couleur = rand() % 5;

    //pilositer = rand() % 100;

    taille = (float)(rand() % 1500);

    nouv = malloc(sizeof(Individu));

    nouv->couleur = couleur;
    nouv->type_peau = peau;
    nouv->regime = regime;
   // nouv->pilosite = pilositer;
    nouv->taille = taille;
    //nouv->independance = indepence;

    return nouv;
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

Individu* creer_individu_random()
{
    Individu* new = malloc(sizeof(Individu));
    new->independance = (float)rand_ab(0,100) / 100;
    new->longueur_fourrure = rand_ab(0,2);
    new->taille = (float)rand_ab(0,200) / 100;
    new->type_peau = rand_ab(0,2);
    new->regime = rand_ab(0,2);
    new->couleur = rand_ab(0,4);
    new->teinte = rand_ab(0,4);
    new->vitesse = rand_ab(0,2);
    new->predation = (float)rand_ab(0,100) / 100;
    return new;
}
