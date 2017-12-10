
#ifndef INDIVIDU_H
#define INDIVIDU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define HERBIVORE 0
#define OMNIVORE  1
#define CARNIVORE 2


// structure de description de traits
typedef struct destraits
{
    size_t inter; // interagi avec l'index "inter" de l'environnement
    char* nom; // nom du trait
}Destraits;

// traits
typedef struct traits{
    float coef; // coef du trait
}Traits;

// structure individu
typedef struct individu{
    size_t generation;  // génération de l'individe
    float independance; // indépendance de l'individu (utile croisement.h)
    Traits* trs; // liste de traits
}Individu;

// individu fixe (utile pour la création)
typedef struct individu_fix{
    float poils;
    float palmes;
    float herbi;
    float carni;
}Individu_fix;

// affiche un individu sur stdout
// ind: l'individu
// dtrs: description des traits (Destraits)
// n: nombre de traits
void afficher_individu(const Individu * ind, const Destraits* dtrs, size_t n);

// affiche un individu fixe
// ind: individu fixe à afficher
void afficher_int_fix(const Individu_fix* ind);

// créer un individu avec des valeurs random
//n : nombre de traits
// retourne un individu
Individu* creer_individu_random(size_t n);

// créér un individu à partir d'un invididu fixe
// n: nombre de trait
// ind: individu fixe
// retourne un individu
Individu* creer_individu_vals(size_t n, const Individu_fix* ind);

// libere un individu
void liberer_individu(Individu** ind);
#endif
