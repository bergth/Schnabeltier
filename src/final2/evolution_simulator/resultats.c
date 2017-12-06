#include "resultats.h"




Stats get_stats(const graph* g, size_t trait)
{
	Stats new;
	new.nom = strdup(g->trs[trait].nom);
	int n = 0;
	float sum = 0;
	float sum2 = 0;
	for(size_t i = g->min; i < g->order; i++)
	{
		if(g->idTable[i].dead != 1)
		{
			float res = g->idTable[i].ind->trs[trait].coef;
			n += 1;
			sum += res;
			sum2 += powf(res, 2);
		}
	}
	new.n = n;
	new.moy = sum / (float)n;
	new.variance = (sum2/(float)n) - powf(new.moy, 2);
	if(new.variance <= 0)
		new.variance = 0;
	new.equart = sqrtf(new.variance);
	return new;
}


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

Resultats* get_resultat(const graph* g)
{
	Resultats* new = calloc(sizeof(Resultats),1);

	new->n = g->nb_traits;
	new->sts = calloc(sizeof(Stats), new->n);
	for(size_t i = 0; i < new->n; i++)
	{
		new->sts[i] = get_stats(g, i);
	}
    return new;
}

void print_resultat(const Resultats* r)
{
	printf("n: %d\n", r->sts[0].n);
	printf("             | moy      | variance | equart   |\n");
	printf("-------------+----------+----------+----------+\n");
	
	for(size_t i = 0; i < r->n; i++)
	{
		printf("%s:      |%10.5f|%10.5f|%10.5f|\n", r->sts[i].nom, r->sts[i].moy, r->sts[i].variance, r->sts[i].equart);
		printf("-------------+----------+----------+----------+\n");
	}
}

/*
typedef struct resultats{
	Stats* taille;
    Stats* longueur_fourrure;
    Stats* type_peau; 
    Stats* regime; 
    Stats* couleur;
    Stats* teinte;
    Stats* vitesse;
} Resultats;

*/


void free_resultats(Resultats** r)
{
	if(r != NULL && *r != NULL)
	{
		for(size_t i = 0; i < (*r)->n; i++)
		{
			free((*r)->sts[i].nom);
		}
		free((*r)->sts);
		free(*r);
		r = NULL;
	}
}