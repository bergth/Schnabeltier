#include "croisement.h"
#include "environnement.h"
#include "graph.h"
#include "individus.h"
#include "survie.h"
#include "utile.h"

#define NB_MAX_IND 10000
#define NB_INIT_IND 100

int main()
{
	printf("Hello Schnabeltier !\n");
	Environnement* env =  Creer_Milieu ();
	Afficher_Milieu(env);

	graph* G = init_graph(NB_MAX_IND);
	inits_nodes(G, NB_INIT_IND);
	
	free(env);
	free_graph(&G);
	printf("Good by Schnabeltier !\n");
	return 0;
}

