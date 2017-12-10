#include "individus.h"
#include "environnement.h"
#include "survie.h"
#include "utile.h"

float esperance_vie(int x)
{
    return powf(10,-7)*powf((float)x,7);
}

float survie_continue(float c_ind, float c_env)
{
    float a = c_ind;
    float b = c_env;
    float res =  expf(-powf(2*(-b+a), 2));
    return res;
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
    return 0;
}

