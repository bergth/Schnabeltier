#include<stdio.h>
#include<stdlib.h>
#include<sqlite3.h>

#include "individus.h"
#include "utile.h"
#include "graph.h"


sqlite3* create_database(const char* filename);

char* create_table_rq(const Destraits* trs,size_t n_trs);

char* create_insert_rq(const Destraits* trs, const Individu* ind, size_t n, size_t i, int dead);

void insert_value(sqlite3* db, const Destraits* trs, const Individu* ind, size_t n, size_t i, int dead);

void create_table(sqlite3* db, const Destraits* trs,size_t n_trs);

void write_database(const char* filename, const graph* g);