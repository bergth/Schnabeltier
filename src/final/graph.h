#ifndef GRAPH_H
#define GRAPH_H


#include <stdio.h>
#include <stdlib.h>
#include "individus.h"
#include "croisement.h"
#include "utile.h"
#include "environnement.h"
#include "survie.h"

typedef struct list{
    int id;
    struct list* next;
}list;

typedef struct node{
    int id;
    Individu* ind;
    int dead;
    list* child;
    list* parents;
}node;


typedef struct graph{
    int order;
    int min;
    int max;
    node* idTable;
}graph;

graph* init_graph(int order);

void free_graph(graph** g);
void free_list(list* l);

void child_born(graph* g, int par1, int par2);

void toDot(const graph* g, const char* filename);

void tmp_init_node(graph* g, int peau, int regime);
void tmp_inits_nodes(graph* g, int n, int peau, int regime);
void inits_nodes(graph* G, size_t n);
void kill_ind(graph* g,const Environnement* env);
#endif