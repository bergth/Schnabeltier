#include "graph.h"
#include "croisement.h"

graph* init_graph(int max)
{
    graph* g = malloc(sizeof(graph));
    g->order = 0;
    g->max = max;
    g->idTable = calloc(sizeof(node), max);
    return g;
}

void free_graph(graph** g)
{
    for(int i = 0; i < (*g)->max; i++)
    {
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

void add_list(list** l, int nb)
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

void child_born(graph* g, int par1, int par2)
{
    if(g->order == g->max)
    {
        fprintf(stderr, "Erreur, graph max atteind\n");
        exit(EXIT_FAILURE);
    }
    node* npar1 = g->idTable + par1;
    node* npar2 = g->idTable + par2 ;
    node* new = g->idTable + g->order;
    new->ind = croisement(npar1->ind, npar2->ind);
    new->child = NULL;
    new->parents = NULL;
    add_list(&(new->parents), par1);
    add_list(&(new->parents), par2);
    add_list(&(npar1->child), g->order);
    add_list(&(npar2->child), g->order);
    (g->order)++;
}


void tmp_init_node(graph* g)
{
    node* new = g->idTable + g->order;
    new->parents = NULL;
    new->child = NULL;
    new->ind = NULL;
    (g->order)++;
}

void tmp_inits_nodes(graph* g, int n)
{
    for(int i = 0; i < n; i++)
    {
        tmp_init_node(g);
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
    for(int i = 0; i < g->order; i++)
    {
        list* tmp = g->idTable[i].child;
        while(tmp != NULL)
        {
            fprintf(f, "%d -> %d\n", i, tmp->id);
            tmp = tmp->next;
        }
    }
    fprintf(f, "}\n");
    fclose(f);
}
