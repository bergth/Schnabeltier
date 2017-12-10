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
#include "mutation.h"

// liste utilisée pour pointer sur les parents
typedef struct list{
    size_t id;
    struct list* next;
}list;

// structure d'un noeud du graphe
typedef struct node{
    int id;
    Individu* ind;
    int dead;
    list* child;
    list* parents;
}node;

// structure du graphe
typedef struct graph{
    size_t order; // ordre du graphe
    size_t min; // minimum non morte
    size_t max; // ordre max du graphe
    size_t nb_traits; // nombre de traits
    Destraits* trs; // tableau de description des traits
    node* idTable; // table d'index des individus
}graph;

// initialise un graphe d'ordre n
graph* init_graph(size_t order);

// libère un graphe
void free_graph(graph** g);
// libère une liste
void free_list(list* l);

// naissance d'un enfant:
// g: le graphe
// par1, par2: index des parents
void child_born(graph* g, size_t par1, size_t par2, size_t gen);
// dessine le graph au format graphviz (debug)
// g: le graphe
// filename: chemin du fichier dot résultant
void toDot(const graph* g, const char* filename);

// initialise les noeud à partire d'une structure fixe
// g: le graphe
// n : nombre de noeuds à créer
// ind: individu fixe (individu.h)
void inits_nodes(graph* g, size_t n, const Individu_fix* ind);

// tue les individus en fonction d'une fonction de survie (survie.h)
// g: le graphe
// env: l'environnement
// gen: la génération pendant laquelle les individus sont tués
float kill_ind(graph* g,const Environnement* env, size_t gen);
// créé une description d'individu type
// trs: pointeurs sur le nouveau tableau de traits
// nb_traits: pointeur sur le nouveau nombre de traits
void creer_individu_type(Destraits** trs, size_t* nb_traits);
#endif