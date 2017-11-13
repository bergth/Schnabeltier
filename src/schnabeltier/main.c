#include <stdio.h>
#include <stdlib.h>

#include "individus.h"
#include "utile.h"
#include "croisement.h"
#include <time.h>

int main()
{
    srand(time(NULL));

    test_croisement();

    /*test_individus();
    char buf[10];
    saisie_securisee(buf,10);
    printf("[%s]\n",buf);
    saisie_securisee(buf,10);
    printf("[%s]\n",buf);
    int val = saisie_entier();
    printf("[%d]\n", val);
    printf("Hello Schnabeltier\n");*/
    fflush(stdout);
    return 0;
}


