#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "time.h"

int rand_ab(int a, int b)
{
    if(a >= b)
        return -1;
    return rand()%(b-a) + a;
}

void rand_acc(graph* g)
{
    int val1 = 0;
    int val2 = 0;
    do
    {
    val1 = rand_ab(0, g->order);
    val2 = rand_ab(0, g->order);
    printf("[%d][%d]\n", val1, val2);
    }while(val1 == val2);

    child_born(g, val1, val2);
}


int main()
{
    srand(time(NULL));
    graph* g = init_graph(10000);
    tmp_inits_nodes(g, 100);
    printf("[%d]\n",g->order);
    for(int i = 0; i < 1000; i++)
    {
        rand_acc(g);
    }
    toDot(g, "graph.dot");
    free_graph(&g);
    return 0;
}
