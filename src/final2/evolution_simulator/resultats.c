#include "resultats.h"

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

float get_taille(const graph* g, size_t i)
{
	return (float)g->idTable[i].ind->taille;
}

float get_longueur_fourrure(const graph* g, size_t i)
{
	return (float)g->idTable[i].ind->longueur_fourrure;
}


float get_regime(const graph* g, size_t i)
{
	return (float)g->idTable[i].ind->regime;
}

float get_couleur(const graph* g, size_t i)
{
	return (float)g->idTable[i].ind->couleur;
}

float get_palmes(const graph* g, size_t i)
{
	return (float)g->idTable[i].ind->palmes;
}

float get_predation(const graph* g, size_t i)
{
	return (float)g->idTable[i].ind->predation;
}

float get_taux_reprod(const graph* g, size_t i)
{
	return g->idTable[i].ind->taux_reprod;
}

Stats* get_stats(const graph* g, getter get)
{
	Stats* new = malloc(sizeof(Stats));
	int n = 0;
	float sum = 0;
	float sum2 = 0;
	for(size_t i = g->min; i < g->order; i++)
	{
		if(g->idTable[i].dead != 1)
		{
			float res = (*get)(g, i);
			n += 1;
			sum += res;
			sum2 += powf(res, 2);
		}
	}
	new->n = n;
	new->moy = sum / (float)n;
	new->variance = (sum2/(float)n) - powf(new->moy, 2);
	if(new->variance <= 0)
		new->variance = 0;
	new->equart = sqrtf(new->variance);
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

	new->taille = get_stats(g, &get_taille);
    new->longueur_fourrure = get_stats(g, &get_longueur_fourrure);
    new->palmes = get_stats(g, &get_palmes);
	new->regime = get_stats(g, &get_regime); 
    new->couleur = get_stats(g, &get_couleur);
    return new;
}

void print_resultat(const Resultats* r)
{
	printf("n: %d\n", (r->taille)->n);
	printf("             | moy      | variance | equart   |\n");
	printf("-------------+----------+----------+----------+\n");
	printf("taille:      |%10.5f|%10.5f|%10.5f|\n", r->taille->moy, r->taille->variance, r->taille->equart);
	printf("-------------+----------+----------+----------+\n");
	printf("fourrure:    |%10.5f|%10.5f|%10.5f|\n", r->longueur_fourrure->moy, r->longueur_fourrure->variance, r->longueur_fourrure->equart);
	printf("-------------+----------+----------+----------+\n");
	printf("palmes:      |%10.5f|%10.5f|%10.5f|\n", r->palmes->moy, r->palmes->variance, r->palmes->equart);
	printf("-------------+----------+----------+----------+\n");
	printf("couleur:     |%10.5f|%10.5f|%10.5f|\n", r->couleur->moy, r->couleur->variance, r->couleur->equart);
	printf("-------------+----------+----------+----------+\n");
	/*printf("teinte:      |%10.5f|%10.5f|%10.5f|\n", r->teinte->moy, r->teinte->variance, r->teinte->equart);
	printf("-------------+----------+----------+----------+\n");
	printf("vitesse:     |%10.5f|%10.5f|%10.5f|\n", r->vitesse->moy, r->vitesse->variance, r->vitesse->equart);
	printf("-------------+----------+----------+----------+\n");
	*/
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
		if((*r)->taille)
			free((*r)->taille);
		if((*r)->longueur_fourrure)	
			free((*r)->longueur_fourrure);
		if((*r)->type_peau)
			free((*r)->type_peau);
		if((*r)->regime)
			free((*r)->regime);
		if((*r)->couleur)
			free((*r)->couleur);
		if((*r)->teinte)
			free((*r)->teinte);
		if((*r)->vitesse)
			free((*r)->vitesse);
		if((*r)->palmes)
			free((*r)->vitesse);
		free(*r);
		*r = NULL;
	}
}