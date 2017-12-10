#include "graph.h"

graph* init_graph(size_t max)
{
    graph* g = malloc(sizeof(graph));
    g->order = 0;
    g->min = 0;
    g->max = max;
    g->idTable = calloc(sizeof(node), max);
    creer_individu_type(&(g->trs),&(g->nb_traits));
    return g;
}

void free_graph(graph** g)
{
    for(size_t i = 0; i < (*g)->max; i++)
    {
        liberer_individu(&((*g)->idTable[i].ind));
        free_list((*g)->idTable[i].child);
        free_list((*g)->idTable[i].parents);
    }
    free((*g)->idTable);
    for(size_t i = 0; i < (*g)->nb_traits; i++)
    {
        free((*g)->trs[i].nom);
    }
    free((*g)->trs);
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

void child_born(graph* g, size_t par1, size_t par2, int gen)
{
    if(g->order >= g->max)
    {
        fprintf(stderr, "Erreur, graph max atteind\n");
        exit(EXIT_FAILURE);
    }
    g->idTable[g->order].ind = croisement(g->idTable[par1].ind, g->idTable[par2].ind, g->trs, g->nb_traits, gen);
    mutation(g->idTable[g->order].ind,g->trs,g->nb_traits);
    g->idTable[g->order].child = NULL;
    g->idTable[g->order].parents = NULL;
    add_list(&(g->idTable[g->order].parents), par1);
    add_list(&(g->idTable[g->order].parents), par2);
    add_list(&(g->idTable[par1].child), g->order);
    add_list(&(g->idTable[par2].child), g->order);
    (g->order)++;
}


void inits_nodes(graph* g, size_t n, const Individu_fix* ind)
{
    for(size_t i = 0; i < n; i++)
    {
        node* new = g->idTable + g->order;
        new->parents = NULL;
        new->child = NULL;
        new->dead = 0;
        if(ind == NULL)
            new->ind = creer_individu_random(g->trs, g->nb_traits);
        else
            new->ind = creer_individu_vals(g->nb_traits, ind);
        (g->order)++;
    }
}

float kill_ind(graph* g,const Environnement* env, int gen)
{
    int n = 0;
    int d = 0;
    for(size_t i = 0; i < g->order; i++)
    {
        if(g->idTable[i].dead)
        {
            if(i > g->min)
                g->min = i;
        }
        else
        {
            n++;
            if(survie_globale(g->idTable[i].ind,g->trs, g->nb_traits,env, gen))
            g->idTable[i].dead = gen;
            if(g->idTable[i].dead)
                d++;
        }
    }
    if(n == 0)
        return -1;
    return (float)d/(float)n;
}

void mute_ind(graph* g)
{
    for(size_t i = g->min; i < g->order; i++)
    {
        if(g->idTable[i].dead == 0)
        {
            mutation(g->idTable[i].ind, g->trs, g->nb_traits);
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
