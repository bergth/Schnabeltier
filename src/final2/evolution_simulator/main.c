#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "croisement.h"
#include "environnement.h"
#include "graph.h"
#include "individus.h"
#include "survie.h"
#include "utile.h"
#include "resultats.h"

#define NB_MAX_IND 150000
#define NB_INIT_IND 100
#define NB_CYBLE 1000

void print_etat(const graph* G)
{
	Resultats* r = get_resultat(G);
	print_resultat(r);
	free_resultats(&r);
}

void cycle(graph* G, const Environnement* env)
{
	kill_ind(G, env);
	//printf("kill: [%f]\n", kill);
	int par1 = 0;
	int par2 = 0;


	
	for(int i = 0; i < 100; i++)
	{
		int n = 0;
		do
		{
			n++;
			par1 = rand_ab((int)G->min, (int)(G->order - 1));
			par2 = rand_ab((int)(G->min), (int)(G->order - 1));
		}while( n < 20 && (par1 == par2 || G->idTable[par1].dead || G->idTable[par2].dead));
		child_born(G, (size_t)par1, (size_t)par2);
	}
}

int main()
{

	/*float res = survie_fourure(2,-30);
	printf("res: [%f]", res);
	return 0;*/
	srand((unsigned int)time(NULL));
	printf("Hello Schnabeltier !\n");
	Environnement* env =  creer_env(1,0,0,42);
	Afficher_Milieu(env);

	graph* G = init_graph(NB_MAX_IND);
	inits_nodes(G, NB_INIT_IND);

	print_etat(G);

	for(int i = 0; i < NB_CYBLE; i++)
	{
	  //  printf("CYCLE: %d\n", i);
		cycle(G,env);
	//	getchar();
	}
	print_etat(G);
	kill_ind(G, env);
	print_etat(G);

	free(env);
	free_graph(&G);
	printf("Good by Schnabeltier !\n");
	return 0;
}

