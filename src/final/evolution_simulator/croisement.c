#include <stdio.h>
#include <stdlib.h>
#include"croisement.h"

int croisement_discret(int trait1, int trait2)
{
    int dom, rec, prob;

    if((trait1 % 2) !=  (trait2 % 2))
    {

        if(trait1 % 2 == 0 && trait2 % 2 != 0)
        {
            dom = trait1;
            rec = trait2;

        }


        else if(trait2 % 2 == 0 && trait1 % 2 !=0)
        {
            dom = trait2;
            rec = trait1;

        }

        prob = rand()%100;



        if(prob > 75)
            return rec;

        else
            return dom;

    }

    else if((trait1 %2 ) == (trait2 % 2))
    {
        if(trait1 >= trait2)
        {
            dom = trait1;
            rec = trait2;
        }

        else if(trait1 < trait2)
        {
            dom = trait2;
            rec = trait1;
        }

        prob = rand()%100;

        if(prob>95)
            return rec;

        else
            return dom;

    }

    return -1;

}

/*float aleatoire(void)
{
    float retour;

    do
    {
        retour = (float)rand()%120;
    }while(retour<75);

    return retour;

}*/

float croisement_continue(float trait1, float trait2, float coef)
{

    float resultat, t1, t2, coefmod;
    int random;

   // printf("trait1=%f trait2=%f\n",trait1,trait2);

    t1 = (trait1 * rand_ab(75,120))/100.0;

    t2 = (trait2 * rand_ab(75,120))/100.0;

    resultat=(t1+t2)/2;

    if(trait1<=0 || trait2<=0)
    {
        printf("[%f][%f][%f]\n", resultat, trait1, trait2);
        exit(EXIT_FAILURE);
    }

   // printf("[%f][%f][%f]\n", resultat, trait1, trait2);

     if(resultat>coef)
     {

        random = rand() % 2;

        if(random == 0)
            coefmod = (-1)*coef;
        else
            coefmod = coef;
     }

     else
        coefmod = 0;




    resultat = ((t1+t2)/2) + coefmod;
    if(resultat <= 0.00)
    {
        printf("[%f][%f][%f]\n", resultat, trait1, trait2);
        exit(EXIT_FAILURE);
    }



    return resultat;
}

Individu* croisement(Individu* ind1, Individu* ind2)
{
    //printf("In croisement: \n");
   /* afficher_individu(ind1);
    afficher_individu(ind2);*/
    Individu* enfant = NULL;

    enfant = malloc(sizeof(Individu));

    enfant->independance = ind1->independance;

    enfant->type_peau = croisement_discret(ind1->type_peau,ind2->type_peau);

    enfant->couleur = croisement_discret(ind1->couleur,ind2->couleur);

    enfant->regime = croisement_discret(ind1->regime,ind2->regime);

    //enfant->pilosite = croisement_continue(ind1->pilosite,ind2->pilosite,enfant->independance);

    enfant->taille = croisement_continue(ind1->taille,ind2->taille,enfant->independance);
    enfant->longueur_fourrure = croisement_continue(ind1->longueur_fourrure,ind2->longueur_fourrure, enfant->independance);


    return enfant;
}

/*void test_croisement(void)
{
    Individu parent1 = {25,1,53,1,2,15};
    Individu parent2 = {63,1,78,0,2,15};
    Individu *enfant=NULL;

    //parent1 = malloc(sizeof(Individu));
    //parent2 = malloc(sizeof(Individu));


    enfant = croisement(&parent1,&parent2);

    afficher_individu(enfant);

    free(enfant);
}*/
