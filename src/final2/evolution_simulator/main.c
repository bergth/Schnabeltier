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
#include "mutation.h"
#include "dbase.h"

#define NB_MAX_IND 1500000
#define NB_INIT_IND 100
#define NB_CYBLE 100

void print_etat(const graph* G)
{
	Resultats* r = get_resultat(G);
	print_resultat(r);
	free_resultats(&r);
	printf("min:   [%ld]\n",G->min);
	printf("order: [%ld]\n", G->order);
}

void cycle(graph* G, const Environnement* env, int gen)
{
	//float kill = 
	kill_ind(G, env,gen);

	mute_ind(G);

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

		int nb_child = rand_ab(1,8);
		for(int i = 0; i < nb_child; i++)
		{
			child_born(G, (size_t)par1, (size_t)par2, gen);
		}
	}
	//getchar();
}

int main()
{

	/*float res = survie_fourure(2,-30);
	printf("res: [%f]", res);
	return 0;*/
	srand((unsigned int)time(NULL));
	printf("Hello Schnabeltier !\n");
	Environnement* env =  creer_env(0.5f,1.0f,1,43);
	Afficher_Milieu(env);

	graph* G = init_graph(NB_MAX_IND);
	inits_nodes(G, NB_INIT_IND);

	print_etat(G);

	for(int i = 0; i < NB_CYBLE; i++)
	{
	  //  printf("CYCLE: %d\n", i);
		cycle(G,env,i);
	//	getchar();
	}
	print_etat(G);
	write_database("test.db",G);
	free_graph(&G);
	Liberer_env(&env);
	printf("Good by Schnabeltier !\n");
	return 0;
}

