#include "graph.h"

graph* init_graph(size_t max)
{
    graph* g = malloc(sizeof(graph));
    g->order = 0;
    g->min = 0;
    g->max = max;
    g->idTable = calloc(sizeof(node), max);
    return g;
}

void free_graph(graph** g)
{
    for(size_t i = 0; i < (*g)->max; i++)
    {
        free((*g)->idTable[i].ind);
        free_list((*g)->idTable[i].child);
        free_list((*g)->idTable[i].parents);
    }
    free((*g)->idTable);
    free(*g);
    *g = NULL;
}

void free_list(list* l)
{
    if(l != NULL)
    {
        list* next = l->next;
        while(next != NULL)
        {
            free(l);
            l = next;
            next = next->next;
        }
        free(l);
    }
}

void add_list(list** l, size_t nb)
{
    list* new = malloc(sizeof(list));
    new->id = nb;
    new->next = NULL;
    if(*l == NULL)
        *l = new;
    else
    {
        list* tmp = *l;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}

void child_born(graph* g, size_t par1, size_t par2)
{
    if(g->order == g->max)
    {
        fprintf(stderr, "Erreur, graph max atteind\n");
        exit(EXIT_FAILURE);
    }
    /*node* npar1 = g->idTable + par1;
    node* npar2 = g->idTable + par2;
    node* new = g->idTable + g->order;
    new->ind = croisement(npar1->ind, npar2->ind);*/

   /* afficher_individu(g->idTable[par1].ind);
    afficher_individu(g->idTable[par2].ind);*/

    g->idTable[g->order].ind = croisement(g->idTable[par1].ind, g->idTable[par2].ind);
    // printf("child: [%p]\n", new->ind);
    g->idTable[g->order].child = NULL;
    g->idTable[g->order].parents = NULL;
    add_list(&(g->idTable[g->order].parents), par1);
    add_list(&(g->idTable[g->order].parents), par2);
    add_list(&(g->idTable[par1].child), g->order);
    add_list(&(g->idTable[par2].child), g->order);
    (g->order)++;
}


void tmp_init_node(graph* g, int peau, int regime)
{
    node* new = g->idTable + g->order;
    new->parents = NULL;
    new->child = NULL;
    new->ind = nouvel_individus(peau, regime);
    (g->order)++;
}

void tmp_inits_nodes(graph* g, int n, int peau, int regime)
{
    for(int i = 0; i < n; i++)
    {
        tmp_init_node(g, peau, regime);
    }
}

void inits_nodes(graph* g, size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        node* new = g->idTable + g->order;
        new->parents = NULL;
        new->child = NULL;
        new->dead = 0;
        new->ind = creer_individu_random();
        (g->order)++;
    }
}

void kill_ind(graph* g,const Environnement* env)
{
    for(size_t i = 0; i < g->order; i++)
    {
        if(g->idTable[i].dead == 1)
        {
            if(i > g->min)
                g->min = i;
        }
        else
        {
            g->idTable[i].dead = survie_globale(g->idTable[i].ind,env);
        }
    }
}

void toDot(const graph* g, const char* filename)
{
    FILE* f = fopen(filename, "w");
    if(f == NULL)
    {
        fprintf(stderr, "Error creating dot file\n");
        exit(EXIT_FAILURE);
    }
    fprintf(f, "digraph grap {\n");
    for(size_t i = 0; i < g->order; i++)
    {
        list* tmp = g->idTable[i].child;
        while(tmp != NULL)
        {
            fprintf(f, "%ld -> %ld\n", i, tmp->id);
            tmp = tmp->next;
        }
    }
    fprintf(f, "}\n");
    fclose(f);
}
