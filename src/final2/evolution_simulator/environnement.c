#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "environnement.h"





uint32_t definir_couleur(float temp, float hum)
{
    (void)hum;
    (void)temp;
    /*uint8_t r = 0, b = 0;
    if(temp >= 30)
    {
        r += ((temp - 30)/20) * 255;
    }
    else
    {
        b += ((100 + temp)/130) * 255;
    }
    uint32_t res = 0;
    res += (r << 2);
    res += (255 << 1);
    res += b;*/
    return 0xFFFFFF;
}

float definir_vegetation(float temp, float hum)
{
    float x = temp;
    float y = hum;
    if(y == 0)
        return 0;

    // f(x,y)=ℯ^(-(3 (-1+2x))^(2))y^(2.5)
    return expf(-3*powf(-1+2*x,2))*powf(y,2.5);
}

Environnement* creer_env(float temp, float hum, float eau, float pcar)
{
    Environnement* new = calloc(sizeof(Environnement), 1);
    new->n_caracts = 5;
    new->caracts = calloc(sizeof(Ecaract),5);
    new->caracts[0].coef = temp;
    new->caracts[0].nom = strdup("Temperature");
    new->caracts[1].coef = hum;
    new->caracts[1].nom = strdup("Humidité");    
    new->caracts[2].coef = pcar;
    new->caracts[2].nom = strdup("% carnivores");
    new->caracts[3].coef = definir_vegetation(temp,hum);
    new->caracts[3].nom = strdup("% vegetation");
    new->caracts[4].coef = eau;
    new->caracts[4].nom = strdup("% eau");
    return new;
}


void Afficher_Milieu (const Environnement* env)
{
    printf("[ENVIRONNEMENT]----------\n");
   for(size_t i = 0; i < env->n_caracts; i++)
   {
        printf("[%s] -> [%f]\n", env->caracts[i].nom, env->caracts[i].coef);
   }
}

void Liberer_env(Environnement** env)
{
    for(size_t i = 0; i < (*env)->n_caracts; i++)
    {
        if((*env)->caracts[i].nom)
        {
            free((*env)->caracts[i].nom);
        }
    }
    free((*env)->caracts);
    free(*env);
    *env = NULL;
}