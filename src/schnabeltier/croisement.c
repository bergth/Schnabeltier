#include <stdio.h>
#include <stdlib.h>


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

float aleatoire(void)
{
    float retour;

    do
    {
        retour = rand()%125;
    }while(retour<25);

    return retour;

}

float croisement_continue(float trait1, float trait2, float coef)
{

    float resultat, t1, t2, coefmod, random;

    t1 = trait1 * aleatoire();

    t2 = trait2 * aleatoire();

    random = rand() % 2;

    if(random == 0)
        coefmod = (-1)*coef;
    else
        coefmod = coef;


    resultat = ((t1*t2)/2) + coefmod;


    return resultat;
}



