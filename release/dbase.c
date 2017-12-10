#include "dbase.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   (void)NotUsed;
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

sqlite3* create_database(const char* filename)
{
    sqlite3 *db;
    if(sqlite3_open(filename, &db))
    {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    }
    return db;
}

char* create_table_rq(const Destraits* trs,size_t n_trs)
{
    char* sql = NULL;
    const char* head =  "CREATE TABLE EVOLUTION(" \
                        "ID INT PRIMARY KEY NOT NULL," \
                        "DEAD INT NOT NULL," \
                        "GEN INT NOT NULL," \
                        "PAR1 INT NOT NULL," \
                        "PAR2 INT NOT NULL,";
    sql = strdup(head);
    for(size_t i = 0; i < n_trs; i++)
    {
        char* tmp = malloc(sizeof(char*));
        tmp[0] = '\0';
        contat(&tmp, trs[i].nom);
        contat(&tmp, " double NOT NULL");
        if(i != n_trs - 1)
        {
            contat(&tmp, ",");
        }
        else
        {
            contat(&tmp, ");");
        }
        contat(&sql,tmp);
        free(tmp);
    }
    return sql;
}

char* create_insert_rq(const Destraits* trs, const Individu* ind, size_t n, size_t i, int dead, int par1, int par2)
{
    char* sql = NULL;
    const char* head =  "INSERT INTO EVOLUTION (ID,DEAD,GEN,PAR1,PAR2,";
    sql = strdup(head);
    for(size_t i = 0; i < n; i++)
    {
        contat(&sql, trs[i].nom);
        if(i != n-1)
            contat(&sql, ",");
        else
            contat(&sql, ") ");
    }
    contat(&sql, "VALUES (");
    
    char str[12];
    sprintf(str, "%ld", i);
    contat(&sql,str);
    contat(&sql,",");

    sprintf(str, "%d", dead);
    contat(&sql,str);
    contat(&sql,",");

    sprintf(str, "%ld", ind->generation);
    contat(&sql,str);
    contat(&sql,",");

    sprintf(str, "%d", par1);
    contat(&sql,str);
    contat(&sql,",");    

    sprintf(str, "%d", par2);
    contat(&sql,str);
    contat(&sql,",");

    for(size_t i = 0; i < n; i++)
    {
        sprintf(str, "%f", ind->trs[i].coef);
        contat(&sql,str);
        if(i != n - 1)
            contat(&sql,",");
        else
            contat(&sql, " );");
    }
    return sql;
}

void insert_value(sqlite3* db, const Destraits* trs, const Individu* ind, size_t n, size_t i, int dead, int par1, int par2)
{
    char* sql = create_insert_rq(trs,ind,n,i,dead,par1,par2);
    char *zErrMsg = 0;
    int rc = sqlite3_exec(db,sql,callback,0, &zErrMsg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }
    free(sql);
}

void create_table(sqlite3* db, const Destraits* trs,size_t n_trs)
{
    char* sql = create_table_rq(trs,n_trs);
    char *zErrMsg = 0;
    int rc = sqlite3_exec(db,sql,callback,0, &zErrMsg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }
    free(sql);
}

void write_database(const char* filename, const graph* g)
{
    char* SQL_ERR = NULL;
    sqlite3* db = create_database(filename);
    create_table(db, g->trs, g->nb_traits);
    sqlite3_exec(db, "BEGIN TRANSACTION", NULL, NULL, &SQL_ERR);
    for(size_t i = 0; i < g->order; i++)
    {
        int par1 = -1, par2 = -1;
        if(g->idTable[i].parents != NULL)
        {
            par1 = (int)(g->idTable[i].parents->id);
            par2 = (int)(g->idTable[i].parents->next->id);
        }
        insert_value(db,g->trs,g->idTable[i].ind,g->nb_traits,i,g->idTable[i].dead,par1,par2);
    }
    sqlite3_exec(db, "END TRANSACTION", NULL, NULL, &SQL_ERR);
    sqlite3_close(db);
}