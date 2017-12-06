#ifndef GRAPH_H
#define GRAPH_H


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "individus.h"
#include "croisement.h"
#include "utile.h"
#include "environnement.h"
#include "survie.h"


typedef struct list{
    size_t id;
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
    size_t order;
    size_t min;
    size_t max;
    size_t nb_traits;
    Destraits* trs;
    node* idTable;
}graph;

graph* init_graph(size_t order);

void free_graph(graph** g);
void free_list(list* l);

void child_born(graph* g, size_t par1, size_t par2, int gen);
void toDot(const graph* g, const char* filename);

void tmp_init_node(graph* g, int peau, int regime);
void tmp_inits_nodes(graph* g, int n, int peau, int regime);
void inits_nodes(graph* G, size_t n);
float kill_ind(graph* g,const Environnement* env);
void creer_individu_type(Destraits** trs, size_t* nb_traits);
#endif