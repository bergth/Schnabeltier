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
            return -(independance*100);
        }

        else
            return (independance*100);
    }

    else
        return 0;

}

int mutation_discrete(int trait, float independance, int modulo)
{
    int r,ecart,r1,indepencancemod;

    r=rand()%100;

    indepencancemod = independance*100;

    if(r<(indepencancemod))
    {
        ecart = (indepencancemod - r)/10;
        ecart = abs(ecart);

        r1=rand()%2;

        if(r1==0)
            return (trait+ecart)%modulo;

        else
            return (trait-ecart)%modulo;
    }

    else
        return trait;


}


int mutation(Individu* ind)
{
    printf("block");
}


