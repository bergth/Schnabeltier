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

void cycle(graph* G, const Environnement* env, size_t gen)
{
	//float kill = 
	kill_ind(G, env,(int)gen);

	//mute_ind(G);

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
			child_born(G, (size_t)par1, (size_t)par2, (int)gen);
		}
	}
	//getchar();
}

void run(size_t init, size_t nb_cycle, size_t max, const char* dbname)
{
	Environnement* env =  creer_env(0.5f,1.0f,1,43);
	Afficher_Milieu(env);

	graph* G = init_graph(max);
	inits_nodes(G, init);

	//print_etat(G);

	for(size_t i = 0; i < nb_cycle; i++)
	{
	  //  printf("CYCLE: %d\n", i);
		cycle(G,env,i);
	//	getchar();
	}
	//print_etat(G);
	printf("Writing database [%s], please wait...\n", dbname);
	write_database(dbname,G);
	printf("Done.\n");
	free_graph(&G);
	Liberer_env(&env);

}

int main(int argc, char*argv[])
{
	if(argc != 4)
	{
		printf("Erreur d'argument:\n");
		printf("./main nb_depart, nb_cycle, nom_db\n");
		exit(EXIT_FAILURE);
	}
	int nb_depart = atoi(argv[1]);
	int nb_cycle = atoi(argv[2]);
	if(nb_depart < 0 || nb_cycle < 0)
	{
		printf("nb_depart et nb_cycle ne peuvent être negatif\n");
		exit(EXIT_FAILURE);
	}
	size_t nb_departabs = (size_t)abs(nb_depart);
	size_t nb_cycleabs = (size_t)abs(nb_cycle);
	srand((unsigned int)time(NULL));
	printf("Hello Schnabeltier !\n");

    run(nb_departabs, nb_cycleabs, 1500000, argv[3]);

	printf("Good by Schnabeltier !\n");
	return 0;
}

