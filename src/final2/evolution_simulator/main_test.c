#include <stdio.h>
#include <stdlib.h>
#include "environnement.h"
#include "individus.h"
#include "survie.h"
#include "croisement.h"
#include "graph.h"
#include "resultats.h"

int main(void)
{
	Environnement* env = creer_env(-100,2,42);
	Afficher_Milieu(env);
	Individu* ind = creer_individu_random();
	afficher_individu(ind);
	free(ind);
	free(env);
	return 0;
}