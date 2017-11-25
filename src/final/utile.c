#include "utile.h"

void vider_buffer()
{
    int c = 0;
    while(c != '\n' && c != EOF)
    {
        c = getchar();
    }
}


void saisie_securisee(char* buf, size_t taille)
{
    if(fgets(buf, taille, stdin) == NULL)
    {
        fprintf(stderr, "Erreur saisie securisee fgets\n");
        exit(EXIT_FAILURE);
    }
    char* res = strchr(buf, '\n');
    if(res != NULL)
    {
        *res = '\0';
    }
    else
    {
        vider_buffer();
    }
}

int saisie_entier()
{
    char buf[40];
    saisie_securisee(buf, 40);
    int res = 0;
    int i = 0;
    for(; i < 40 && buf[i] != '\0'; i++)
    {
        if(buf[i]>= '0' && buf[i] <= '9')
        {
            res *= 10;
            res += buf[i] - '0';
        }
        else
        {
            return -1;
        }
    }
    return res;
}


float saisie_float()
{
    char buf[40];
    saisie_securisee(buf, 40);
    float res = 0;
    int i = 0;
    int n=10;
    for(; i < 40 && buf[i] != '\0'  && buf[i] != '.'; i++)
    {
        if(buf[i]>= '0' && buf[i] <= '9')
        {
            res *= 10;
            res += buf[i] - '0';
        }
        else
        {
            return -1;
        }
    }

    i++;

    for(; i<40 && buf[i] !='\0';i++)
    {
        if(buf[i]>= '0' && buf[i] <= '9')
        {
            res += ((buf[i] - '0')/n);
            n = n*10;
        }
        else
        {
            return -1;
        }

    }

    return res;
}

int rand_ab(int a, int b)
{
    if(a >= b)
        return -1;
    return rand()%(b-a) + a;
}
