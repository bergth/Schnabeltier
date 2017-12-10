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



void mutation(Individu* ind, const Destraits* trs, size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        if(trs[i].cont == 1)
        {
            float res = ind->trs[i].coef + mutation_continue(ind->independance);
            if(res > 1)
                res = 1;
            else if(res < 0)
                res = 0;
            ind->trs[i].coef = res;
        }
        else
        {
            assert(0);
        }
    }
}
