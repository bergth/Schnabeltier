#include "resultats.h"

float get_taille(const graph* g, size_t i)
{
	return g->idTable[i].ind->taille;
}

float get_longueur_fourrure(const graph* g, size_t i)
{
	return g->idTable[i].ind->longueur_fourrure;
}

float get_type_peau(const graph* g, size_t i)
{
	return g->idTable[i].ind->type_peau;
}

float get_regime(const graph* g, size_t i)
{
	return g->idTable[i].ind->regime;
}

float get_couleur(const graph* g, size_t i)
{
	return g->idTable[i].ind->couleur;
}

float get_teinte(const graph* g, size_t i)
{
	return g->idTable[i].ind->teinte;
}

float get_vitesse(const graph* g, size_t i)
{
	return g->idTable[i].ind->vitesse;
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
	new->moy = sum / n;
	new->variance = (sum2/n) - powf(new->moy, 2);
	new->equart = sqrtf(new->variance);
	return new;
}

Resultats* get_resultat(const graph* g)
{
	Resultats* new = malloc(sizeof(Resultats));

	new->taille = get_stats(g, &get_taille);
    new->longueur_fourrure = get_stats(g, &get_longueur_fourrure);
    new->type_peau = get_stats(g, &get_type_peau);
    new->regime = get_stats(g, &get_regime); 
    new->couleur = get_stats(g, &get_couleur);
    new->teinte = get_stats(g, &get_teinte);
    new->vitesse = get_stats(g, &get_vitesse);
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
	printf("peau:        |%10.5f|%10.5f|%10.5f|\n", r->type_peau->moy, r->type_peau->variance, r->type_peau->equart);
	printf("-------------+----------+----------+----------+\n");
	printf("regime:      |%10.5f|%10.5f|%10.5f|\n", r->regime->moy, r->regime->variance, r->regime->equart);
	printf("-------------+----------+----------+----------+\n");
	printf("couleur:     |%10.5f|%10.5f|%10.5f|\n", r->couleur->moy, r->couleur->variance, r->couleur->equart);
	printf("-------------+----------+----------+----------+\n");
	/*printf("teinte:      |%10.5f|%10.5f|%10.5f|\n", r->teinte->moy, r->teinte->variance, r->teinte->equart);
	printf("-------------+----------+----------+----------+\n");
	printf("vitesse:     |%10.5f|%10.5f|%10.5f|\n", r->vitesse->moy, r->vitesse->variance, r->vitesse->equart);
	printf("-------------+----------+----------+----------+\n");
	*/
}

void free_resultats(Resultats** r)
{
	free((*r)->taille);
	free((*r)->longueur_fourrure);
	free((*r)->type_peau);
	free((*r)->regime);
	free((*r)->couleur);
	free((*r)->teinte);
	free((*r)->vitesse);
	free(*r);
	*r = NULL;
}