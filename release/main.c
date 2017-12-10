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

// affiche l'état du graph avec resultat.h
void print_etat(const graph* G)
{
	Resultats* r = get_resultat(G);
	print_resultat(r);
	free_resultats(&r);
	printf("min:   [%ld]\n",G->min);
	printf("order: [%ld]\n", G->order);
}

// effectue un cycle
void cycle(graph* G, const Environnement* env, size_t gen)
{
	kill_ind(G, env,gen);

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
		}while( n < 20 && (par1 == par2 || G->idTable[par1].dead || G->idTable[par2].dead
										|| G->idTable[par1].ind->generation == gen || G->idTable[par2].ind->generation == gen));
		if(n < 20)
		{
			int nb_child = rand_ab(1,8);
			for(int i = 0; i < nb_child; i++)
			{
				child_born(G, (size_t)par1, (size_t)par2, gen);
			}
		}
	}
}

// fait tourner la simulation
// init: nombre d'individu initiaux
// nb_cycle: nombre de cycles
// max: nombre maximum d'individus
// env: environnement
// ind: individu fixe
// dbname: chemin de la base de donnée
void run(size_t init, size_t nb_cycle, size_t max, Environnement* env, const Individu_fix* ind, const char* dbname)
{
	Afficher_Milieu(env);
	if(ind != NULL)
		afficher_int_fix(ind);
	else
		printf("Individu créés aléatoirement\n");
	graph* G = init_graph(max);
	inits_nodes(G, init, ind);

	for(size_t i = 0; i < nb_cycle; i++)
	{
		cycle(G,env,i);
	}
	printf("\nFin de la simulation\n");
	printf("Nombre de cycles: [%ld]\n", nb_cycle);
	printf("Nombre d'individus créés: [%ld]\n", G->order);
	printf("Writing database [%s], please wait...\n", dbname);
	write_database(dbname,G);
	printf("Done.\n");
	free_graph(&G);
	Liberer_env(&env);

}

int main(int argc, char*argv[])
{
	if(argc != 8 && argc != 12)
	{
		printf("Erreur d'argument:\n");
		printf("./main nb_depart, nb_cycle, nom_db, env*(4), [ind*(4)]\n");
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

	float temp = ((float)atoi(argv[4]))/100;
	float hum = ((float)atoi(argv[5]))/100;
	float eau = ((float)atoi(argv[6]))/100;
	float pcar = ((float)atoi(argv[7]))/100;

	Environnement* env = creer_env(temp,hum,eau,pcar);

	Individu_fix* ind = NULL;
	Individu_fix stat;
	if(argc == 12)
	{
		stat.poils = ((float)atoi(argv[8]))/100;
		stat.palmes = ((float)atoi(argv[9]))/100;
		stat.herbi = ((float)atoi(argv[10]))/100;
		stat.carni = ((float)atoi(argv[11]))/100;
		ind = &stat;
	}
	srand((unsigned int)time(NULL));
	printf("Hello Schnabeltier !\n");

    run(nb_departabs, nb_cycleabs, 1500000, env, ind, argv[3]);

	printf("Good by Schnabeltier !\n");
	return 0;
}

