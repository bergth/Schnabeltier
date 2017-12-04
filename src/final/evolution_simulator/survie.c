#include "individus.h"
#include "environnement.h"
#include "survie.h"
#include "utile.h"

#define TAILLE 50


float survie_predateur(Environnement * environnement, Individu * ind)
{
    float survie;

    if (environnement->pourcentage_predateur > 0.5)
        // plus de predateurs que de proies, les predateurs auront moins à manger donc moins de chance de survivre
    {
        survie = environnement->pourcentage_predateur * ind->predation;
    }
    if ((environnement->pourcentage_predateur <= 0.5))

    {
        survie = environnement->pourcentage_predateur + ind->predation;
        if(survie>1) survie = 1;
    }

    return survie;
}


/// Les différentes fonctions de survie

/* Fonction qui retourne la viabilité d'un individu dans son environnement */


int pourcentage_survie_foret( Individu ind)// je calcule le taux de survie => + il est grand plus l'individue a des chance de vivre.
{
 int taux_de_survie_peau=0;
 int taux_globale=0;
 int taux_de_survie_logueure_fourure=0;
 if(ind.type_peau==0) // si le type de peau est écaille, dans la foret l'individu a un pourcentage de vie a 80%
 {
     taux_de_survie_peau=taux_de_survie_peau+0.8;
 }
 else
 {
     if(ind.type_peau==1) // si le type de peau est plume, dans la foret l'individu a un pourcentage de vie a 90%
     {
         taux_de_survie_peau=taux_de_survie_peau+0.9;
     }
     else  // si le type de peau est fourrure, dans la foret l'individu a un pourcentage de vie a 100%
     {
        taux_de_survie_peau=taux_de_survie_peau+1;
     }
 }
 if(ind.longueur_fourrure==0) //si la langeure de fourure de l'individue =0 il a une chance de survie de 50%
 {
     taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.50;
 }
 else
 {
     if(ind.longueur_fourrure==1)//si la langeure de fourure de l'individue est courte il a une chance de survie de 70%
     {
         taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.70;
     }
     else
     {
         if(ind.longueur_fourrure==2)//si la langeure de fourure de l'individue est moyenne il a une chance de survie de 90%
         {
             taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+1;
         }
         else //si la langeure de fourure de l'individue est épaisse il a une chance de survie de 100%
         {
             taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.9;
         }
     }
 }
 taux_globale=(taux_de_survie_logueure_fourure+taux_de_survie_peau)/2;
 return taux_globale;
}


int pourcentage_survie_jungle( Individu ind) // dans la jungle il fais frois ou chaud ?????????
{
 int taux_de_survie_peau=0;
 int taux_globale=0;
 int taux_de_survie_logueure_fourure=0;
 if(ind.type_peau==0) // si le type de peau est écaille, dans la junglel'individu a un pourcentage de vie a 100%
 {
     taux_de_survie_peau=taux_de_survie_peau+1;
 }
 else
 {
     if(ind.type_peau==1) // si le type de peau est plume, dans la jungle l'individu a un pourcentage de vie a 90%
     {
         taux_de_survie_peau=taux_de_survie_peau+0.9;
     }
     else  // si le type de peau est fourrure, dans la jungle l'individu a un pourcentage de vie a 100%
     {
        taux_de_survie_peau=taux_de_survie_peau+1;
     }
 }
 if(ind.longueur_fourrure==0) //si la langeure de fourure de l'individue =0 il a une chance de survie de 10%
 {
     taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.10;
 }
 else
 {
     if(ind.longueur_fourrure==1)//si la langeure de fourure de l'individue est courte il a une chance de survie de 80%
     {
         taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.80;
     }
     else
     {
         if(ind.longueur_fourrure==2)//si la langeure de fourure de l'individue est moyenne il a une chance de survie de 100%
         {
             taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+1;
         }
         else //si la langeure de fourure de l'individue est épaisse il a une chance de survie de 80%
         {
             taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.8;
         }
     }
 }
 taux_globale=(taux_de_survie_logueure_fourure+taux_de_survie_peau)/2;
 return taux_globale;
}


int pourcentage_survie_montagne( Individu ind)
{
 int taux_de_survie_peau=0;
 int taux_globale=0;
 int taux_de_survie_logueure_fourure=0;
 if(ind.type_peau==0) // si le type de peau est écaille, dans la montagne l'individu a un pourcentage de vie a 0%
 {
     taux_de_survie_peau=taux_de_survie_peau+0.00;
 }
 else
 {
     if(ind.type_peau==1) // si le type de peau est plume, dans la montagne l'individu a un pourcentage de vie a 90%
     {
         taux_de_survie_peau=taux_de_survie_peau+0.9;
     }
     else  // si le type de peau est fourrure, dans la montagne l'individu a un pourcentage de vie a 100%
     {
        taux_de_survie_peau=taux_de_survie_peau+1;
     }
 }
 if(ind.longueur_fourrure==0) //si la langeure de fourure de l'individue =0 il a une chance de survie de 10%
 {
     taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.10;
 }
 else
 {
     if(ind.longueur_fourrure==1)//si la langeure de fourure de l'individue est courte il a une chance de survie de 50%
     {
         taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.50;
     }
     else
     {
         if(ind.longueur_fourrure==2)//si la langeure de fourure de l'individue est moyenne il a une chance de survie de 80%
         {
             taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.8;
         }
         else //si la langeure de fourure de l'individue est épaisse il a une chance de survie de 100%
         {
             taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+1;
         }
     }
 }
 taux_globale=(taux_de_survie_logueure_fourure+taux_de_survie_peau)/2;
 return taux_globale;
}


int pourcentage_survie_savane( Individu ind)
{
  int taux_de_survie_peau=0;
 int taux_globale=0;
 int taux_de_survie_logueure_fourure=0;
 if(ind.type_peau==0) // si le type de peau est écaille, dans la savane l'individu a un pourcentage de vie a 0%
 {
     taux_de_survie_peau=taux_de_survie_peau+0.00;
 }
 else
 {
     if(ind.type_peau==1) // si le type de peau est plume, dans la savane l'individu a un pourcentage de vie a 70%
     {
         taux_de_survie_peau=taux_de_survie_peau+0.7;
     }
     else  // si le type de peau est fourrure, dans la savane l'individu a un pourcentage de vie a 100%
     {
        taux_de_survie_peau=taux_de_survie_peau+1;
     }
 }
 if(ind.longueur_fourrure==0) //si la langeure de fourure de l'individue =0 il a une chance de survie de 50%
 {
     taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.50;
 }
 else
 {
     if(ind.longueur_fourrure==1)//si la langeure de fourure de l'individue est courte il a une chance de survie de 90%
     {
         taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.90;
     }
     else
     {
         if(ind.longueur_fourrure==2)//si la langeure de fourure de l'individue est moyenne il a une chance de survie de 90%
         {
             taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.9;
         }
         else //si la langeure de fourure de l'individue est épaisse il a une chance de survie de 70%
         {
             taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.7;
         }
     }
 }
 taux_globale=(taux_de_survie_logueure_fourure+taux_de_survie_peau)/2;
 return taux_globale;
}


float pourcentage_survie_desert( Individu ind)
{
 float taux_de_survie_peau=0;
 float taux_globale=0;
 float taux_de_survie_logueure_fourure=0;
 if(ind.type_peau==0) // si le type de peau est écaille, dans la desert l'individu a un pourcentage de vie a 0%
 {
     taux_de_survie_peau=taux_de_survie_peau+0.00;
 }
 else
 {
     if(ind.type_peau==1) // si le type de peau est plume, dans la desert l'individu a un pourcentage de vie a 10%
     {
         taux_de_survie_peau=taux_de_survie_peau+0.1;
     }
     else  // si le type de peau est fourrure, dans la desert l'individu a un pourcentage de vie a 70%
     {
        taux_de_survie_peau=taux_de_survie_peau+0.7;
     }
 }
 if(ind.longueur_fourrure==0) //si la langeure de fourure de l'individue =0 il a une chance de survie de 20%
 {
     taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.20;
 }
 else
 {
     if(ind.longueur_fourrure==1)//si la langeure de fourure de l'individue est courte il a une chance de survie de 70%
     {
         taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.70;
     }
     else
     {
         if(ind.longueur_fourrure==2)//si la langeure de fourure de l'individue est moyenne il a une chance de survie de 90%
         {
             taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.9;
         }
         else //si la langeure de fourure de l'individue est épaisse il a une chance de survie de 50%
         {
             taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.5;
         }
     }
 }
 taux_globale=(taux_de_survie_logueure_fourure+taux_de_survie_peau)/2;
 return taux_globale;
}


int pourcentage_survie_pleine( Individu ind)
{
 int taux_de_survie_peau=0;
 int taux_globale=0;
 int taux_de_survie_logueure_fourure=0;
 if(ind.type_peau==0) // si le type de peau est écaille, dans la pleine l'individu a un pourcentage de vie a 80%
 {
     taux_de_survie_peau=taux_de_survie_peau+0.8;
 }
 else
 {
     if(ind.type_peau==1) // si le type de peau est plume, dans la pleine l'individu a un pourcentage de vie a 90%
     {
         taux_de_survie_peau=taux_de_survie_peau+0.9;
     }
     else  // si le type de peau est fourrure, dans la pleine l'individu a un pourcentage de vie a 100%
     {
        taux_de_survie_peau=taux_de_survie_peau+1;
     }
 }
 if(ind.longueur_fourrure==0) //si la langeure de fourure de l'individue =0 il a une chance de survie de 70%
 {
     taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.70;
 }
 else
 {
     if(ind.longueur_fourrure==1)//si la langeure de fourure de l'individue est courte il a une chance de survie de 80%
     {
         taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.80;
     }
     else
     {
         if(ind.longueur_fourrure==2)//si la langeure de fourure de l'individue est moyenne il a une chance de survie de 100%
         {
             taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+1;
         }
         else //si la langeure de fourure de l'individue est épaisse il a une chance de survie de 90%
         {
             taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.9;
         }
     }
 }
 taux_globale=(taux_de_survie_logueure_fourure+taux_de_survie_peau)/2;
 return taux_globale;
}


float pourcentage_survie_banquise( Individu ind)
{
 float taux_de_survie_peau=0;
 float taux_globale=0;
 float taux_de_survie_logueure_fourure=0;
 if(ind.type_peau==0) // si le type de peau est écaille, dans la banquise l'individu a un pourcentage de vie a 50%
 {
     taux_de_survie_peau=taux_de_survie_peau+0.5;
 }
 else
 {
     if(ind.type_peau==1) // si le type de peau est plume, dans la banquie l'individu a un pourcentage de vie a 10%
     {
         taux_de_survie_peau=taux_de_survie_peau+0.1;
     }
     else  // si le type de peau est fourrure, dans la banquise l'individu a un pourcentage de vie a 100%
     {
        taux_de_survie_peau=taux_de_survie_peau+1;
     }
 }
 if(ind.longueur_fourrure==0) //si la langeure de fourure de l'individue =0 il a une chance de survie de 0%
 {
     taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.00;
 }
 else
 {
     if(ind.longueur_fourrure==1)//si la langeure de fourure de l'individue est courte il a une chance de survie de 30%
     {
         taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.30;
     }
     else
     {
         if(ind.longueur_fourrure==2)//si la langeure de fourure de l'individue est moyenne il a une chance de survie de 50%
         {
             taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+0.50;
         }
         else //si la langeure de fourure de l'individue est épaisse il a une chance de survie de 100%
         {
             taux_de_survie_logueure_fourure=taux_de_survie_logueure_fourure+1;
         }
     }
 }
 taux_globale=(taux_de_survie_logueure_fourure+taux_de_survie_peau)/2;
 return taux_globale;
}

/*void decrire_choix(int choix, Individu ind) // je regarde par rapport au choix de l'utilasiteur je 'envois sur la fonction qui calcule la survie
{
	if(choix==0)
	{
   		pourcentage_survie_foret(ind);
	}
	if(choix==1)
	{
   		pourcentage_survie_foret(ind);
	}
	if(choix==2)
	{
   		pourcentage_survie_montagne(ind);
	}
	if(choix==3)
	{
  		 pourcentage_survie_savane(ind);
	}
	if(choix==4)
	{
   		pourcentage_survie_desert(ind);
	}
	if(choix==5)
	{
   		pourcentage_survie_pleine(ind);
	}
	if(choix==6)
	{
 	  	pourcentage_survie_banquise(ind);
	}
}*/

int survie_globale(const Individu* ind, const Environnement* env)
{
    (void)env;
   /* int res = 0;
    switch(env->type)
    {
        case FORET:
            res = pourcentage_survie_foret(*ind);
            break;
        case MONTAGNE:
            res = pourcentage_survie_montagne(*ind);
            break;
        case SAVANE:
            res = pourcentage_survie_savane(*ind);
            break;
        case DESERT:
            res = pourcentage_survie_desert(*ind);
            break;
        case PLAINE:
            res = pourcentage_survie_pleine(*ind);
            break;
        case BANQUISE:
            res = pourcentage_survie_banquise(*ind);
            break;
        default:
            fprintf(stderr, "Erreur survie globale: type inconnu\n");
            exit(EXIT_FAILURE);
            break;
    }*/
    //float res = pourcentage_survie_desert(*ind);
   /* float res = pourcentage_survie_banquise(*ind);
    //printf("SURVIE: %f\n", res);
    if(res* 100 > rand_ab(0,100))
        return 1;

    return 0;*/
    //return ind->taille > 1;
    return !(ind->longueur_fourrure <0.90);
}
