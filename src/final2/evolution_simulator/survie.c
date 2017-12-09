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


float esperance_vie(int x)
{
    return powf(10,-7)*powf((float)x,7);
}

float survie_continue(float c_ind, float c_env)
{
    float a = c_ind;
    float b = c_env;
    float res =  expf(-powf(2*(-b+a), 2));
    //printf("[%f][%f] = [%f]\n", a, b, res);
    return res;
    //float dif = fabsf(fourrure - temp);
    //return expf(-powf(2*dif, 2));
}


int survie_globale(const Individu* ind, const Destraits* trs, size_t n_trs, const Environnement* env, int gen)
{
    int n = 0;
    float pourcentage = 0;
    int rand = 0;
    (void)gen;
    pourcentage = esperance_vie(gen - ind->generation);
    rand = rand_ab(0,100);
    if(rand < pourcentage*100)
        return 1;

    for(size_t i = 0; i < n_trs; i++)
    {
        Traits* tr = ind->trs + i;
        if(trs[i].cont)
        {
            n += 1;
            //printf("[%s]\n",env->caracts[trs[i].inter].nom);
            pourcentage = survie_continue(tr->coef, env->caracts[trs[i].inter].coef);
            rand = rand_ab(0,100);
            if(rand > pourcentage*100)
                return 1;
        }
        else
        {
            assert(0);
        }
    }
    pourcentage = pourcentage / (float)n;
    //printf("[%f]\n", pourcentage);
    //int rand = rand_ab(0,100);
    //int res = (rand > pourcentage*100);
    return 0;
}

