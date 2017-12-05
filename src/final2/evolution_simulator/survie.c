#include "individus.h"
#include "environnement.h"
#include "survie.h"
#include "utile.h"


/*float survie_predateur(Environnement * environnement, Individu * ind)
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
}*/


float survie_continue(float c_ind, float c_env)
{
    float a = c_ind;
    float b = c_env;
    float res =  expf(-powf(2*(-b+a), 2));
   // printf("[%f][%f] = [%f]\n", a, b, res);
    return res;
    //float dif = fabsf(fourrure - temp);
    //return expf(-powf(2*dif, 2));
}


int survie_globale(const Individu* ind, const Environnement* env)
{
    //return 1;
    
    //return ind->longueur_fourrure < 10;
    float pourcentage = survie_continue(ind->longueur_fourrure, env->temp);
    //return pourcentage > 0.3;
    int rand = rand_ab(0,100);
    int res = (rand > pourcentage*100);
    if(res)
        return 1;

    pourcentage = survie_continue(ind->palmes, env->eau);
    rand = rand_ab(0,100);
    res = (rand > pourcentage*100);
    //printf("[%f][%d][%d]\n", pourcentage, rand, res);
    return res;
}

