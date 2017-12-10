#include<stdio.h>
#include<stdlib.h>
#include<sqlite3.h>

#include "individus.h"
#include "utile.h"
#include "graph.h"

// Créé une nouvelle base de donnée
// filename: location de la base de donnée à créer
// retourne une donnée de type sqlite3 (la base de donnée)
sqlite3* create_database(const char* filename);

// créé une requette pour la tréation de la table de traits
// trs: Tableau de description e traits (Destraits)
// n_trs: nombre de traits
// retourne une chaine de caractère contenant la requette
char* create_table_rq(const Destraits* trs,size_t n_trs);

// créé une requette pour inserer un nouvel individu dans la base de donnée:
// trs: Tableau de description e traits (Destraits)
// ind: individu à insérer
// n: nombre de trait
// i : index de l'individu
// dead: individu mort où non.
// retourne une chaine de caractère contenant la requette
char* create_insert_rq(const Destraits* trs, const Individu* ind, size_t n, size_t i, int dead, int par1, int par2);
// insère un individu dans la base de donnée
// db: la base de donnée
// trs: Tableau de description e traits (Destraits)
// ind: individu à insérer
// n: nombre de trait
// i : index de l'individu
// dead: individu mort où non.
void insert_value(sqlite3* db, const Destraits* trs, const Individu* ind, size_t n, size_t i, int dead, int par1, int par2);

// Créé la table de traits dans la base de donnée
// db: base de donnée
// trs: Tableau de description e traits (Destraits)
// n_trs: le nombre de traits
void create_table(sqlite3* db, const Destraits* trs,size_t n_trs);

void write_database(const char* filename, const graph* g);