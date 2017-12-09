#include "mutation.h"

float mutation_continue(float independance)
{
    int r, r1;

    r = rand()%100;

    if(r<(independance*100))
    {
        r1=rand()%2;

        if(r1==0)
        {
            return -(independance);
        }

        else
            return (independance);
    }

    else
        return 0;

}

int mutation_discrete(int trait, float independance, int modulo)
{
    int r,ecart,r1,indepencancemod,tmp;

    r=rand()%100;

    indepencancemod = (int)(independance*100);

    if(r<(indepencancemod))
    {
        ecart = (indepencancemod - r)/10;
        ecart = abs(ecart);

        r1=rand()%2;

        if(r1==0)
            return (trait+ecart)%modulo;

        else
        {
            if((trait-ecart)<0)
            {
                tmp = trait - ecart;
                tmp = abs(tmp);
                return tmp%modulo;
            }
            else
                return (trait-ecart)%modulo;
        }

    }

    else
        return trait;


}

/*
void test_mutation(void)
{
    Individu* ind=NULL;

    ind = creer_individu_random();

    afficher_individu(ind);

    mutation(ind);

    afficher_individu(ind);
}
*/

void mutation(Individu* ind, const Destraits* trs, size_t n)
{
   // printf("\n\nblock\n\n");

    for(size_t i = 0; i < n; i++)
    {
        if(trs[i].cont == 1)
        {
            //printf("avant: [%f]", ind->trs[i].coef);
            float res = ind->trs[i].coef + mutation_continue(ind->independance);
            if(res > 1)
                res = 1;
            else if(res < 0)
                res = 0;
            ind->trs[i].coef = res;
           // printf("apres: [%f]\n", ind->trs[i].coef);
        }
        else
        {
            assert(0);
        }
    }


/*
    ind->couleur = mutation_discrete(ind->couleur,ind->independance,8);
    ind->teinte = mutation_discrete(ind->teinte,ind->independance,5);
    ind->longueur_fourrure = mutation_discrete(ind->longueur_fourrure,ind->independance,3);
    ind->regime = mutation_discrete(ind->regime,ind->independance,3);
    printf("regime=%d\n",ind->regime);
    ind->type_peau = mutation_discrete(ind->type_peau,ind->independance,3);
    ind->vitesse = mutation_discrete(ind->vitesse,ind->independance,3);

    ind->predation = ind->predation + mutation_continue(ind->independance);
    ind->survie = ind->survie + mutation_continue(ind->independance);
    ind->taille = ind->taille + (mutation_continue(ind->independance)/100);
*/


}
