#include "individus.h"
#include "utile.h"




Individu* creer_individu_random(const Destraits* dtrs, size_t n)
{
/*
    float independance;
    float taille;
    float longueur_fourrure;
    int couleur;
    int regime;
    int palmes;
    float predation;
    float taux_reprod;
*/
    Individu* new = calloc(sizeof(Individu),1);
    new->generation = 0;
    new->independance = (float)rand_ab(0,1000)/(float)1000;
    new->trs = calloc(sizeof(Traits),n);
    for(size_t i = 0; i < n; i++)
    {
        Traits* tr = new->trs + i;
        if(dtrs[i].cont)
        {
            tr->coef = (float)rand_ab(0,1000)/(float)1000;
        }
        else
        {
            tr->val = rand_ab(0,(int)(dtrs[i].n_dis));
        }
    }
    return new;
}

void afficher_individu(const Individu * ind, const Destraits* dtrs, size_t n)
{
    printf("[INDIVIDU]-----------------------------------\n");
    for(size_t i = 0; i < n; i++)
    {
        const Traits* tr = ind->trs + i;
        if(dtrs[i].cont)
        {
            printf("[%s]: [%f]\n", dtrs[i].nom, tr->coef);
        }
        else
        {
            printf("[%s]: [%s]\n", dtrs[i].nom, dtrs[i].nom_dis[tr->val]);
        }
    }
    printf("[FIN INDIVIDU]-------------------------------\n");
}

void liberer_individu(Individu** ind)
{
    if(ind != NULL && *ind != NULL)
    {
        if((*ind)->trs != NULL)
        {
            free((*ind)->trs);
        }
        free(*ind);
        *ind = NULL;
    }
}