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

	int par1 = 0;
	int par2 = 0;

	for(int i = 0; i < 100; i++)
	{
		do
		{
			par1 = rand_ab(G->min, G->order);
			par2 = rand_ab(G->min, G->order);
		}while(par1 == par2 || G->idTable[par1].dead || G->idTable[par2].dead);

		child_born(G, par1, par2);
	}
}

int main()
{
	srand(time(NULL));
	printf("Hello Schnabeltier !\n");

    Environnement* env =  Creer_Milieu ();
    Afficher_Milieu(env);

	for(int i=0; i<164; i++)
	{


        /*Environnement* env =  Creer_Milieu ();
        Afficher_Milieu(env);*/

        graph* G = init_graph(NB_MAX_IND);
        inits_nodes(G, NB_INIT_IND);

        print_etat(G);

        for(int i = 0; i < NB_CYBLE; i++)
        {
        //  printf("CYCLE: %d\n", i);
            cycle(G,env);
        }

        print_etat(G);

        //free(env);
        free_graph(&G);
	}

	//test_mutation();

	printf("Good by Schnabeltier !\n");
	return 0;
}

