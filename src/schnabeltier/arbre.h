
typedef struct Arbre{
    Individu * ind;
    struct Arbre* fils;
    struct Arbre* frere;
    int mort;
} Arbre;

Arbre* creer_noeud(Individu* ind);
void liberer_arhre(Arbre* A);
