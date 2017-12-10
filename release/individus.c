#include "individus.h"
#include "utile.h"


void creer_trait_continue(Destraits* tr, size_t inter, const char* nom)
{
    tr->inter = inter;
    tr->nom = strdup(nom);
}

void creer_individu_type(Destraits** trs, size_t* nb_traits)
{
    size_t n = 4;
    *trs = calloc(sizeof(Destraits), n);
    creer_trait_continue(*trs + 0,0,"poils");
    creer_trait_continue(*trs + 1,4,"palmes");
    creer_trait_continue(*trs + 2,3,"herbi");
    creer_trait_continue(*trs + 3,2,"carni");
    *nb_traits = n;
}

Individu* creer_individu_vals(size_t n, const Individu_fix* ind)
{
    assert(ind->carni >= 0 && ind->herbi >= 0 && ind->palmes >= 0 && ind->poils >= 0);
    assert(ind->carni <= 1 && ind->herbi <= 1 && ind->palmes <= 1 && ind->poils <= 1);
    Individu* new = calloc(sizeof(Individu),1);
    new->generation = 0;
    new->independance = (float)rand_ab(0,1000)/(float)1000;
    new->trs = calloc(sizeof(Traits),n);
    assert(n == 4);
    new->trs[0].coef = ind->poils;
    new->trs[1].coef = ind->palmes;
    new->trs[2].coef = ind->herbi;
    new->trs[3].coef = ind->carni;
    return new;

}


Individu* creer_individu_random(size_t n)
{
    Individu* new = calloc(sizeof(Individu),1);
    new->generation = 0;
    new->independance = (float)rand_ab(0,1000)/(float)1000;
    new->trs = calloc(sizeof(Traits),n);
    for(size_t i = 0; i < n; i++)
    {
        Traits* tr = new->trs + i;
        tr->coef = (float)rand_ab(0,1000)/(float)1000;
    }
    return new;
}

void afficher_int_fix(const Individu_fix* ind)
{
    printf("[INDIVIDU FIXE]----------\n");
    printf("Poils -> [%f]\n", ind->poils);
    printf("Palmes -> [%f]\n", ind->palmes);
    printf("Carni -> [%f]\n", ind->carni);
    printf("Herbi -> [%f]\n", ind->herbi);
}    

void afficher_individu(const Individu * ind, const Destraits* dtrs, size_t n)
{
    printf("[INDIVIDU]-----------------------------------\n");
    for(size_t i = 0; i < n; i++)
    {
        const Traits* tr = ind->trs + i;
        printf("[%s]: [%f]\n", dtrs[i].nom, tr->coef);

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