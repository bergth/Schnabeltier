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
    float x = hum;
    float y = temp;
    if(y == 0)
        return 0;

    // f(x,y)=ℯ^(-(3 (-1+2x))^(2))y^(2.5)
    return expf(-3*powf(-1+2*x,2))*powf(y,2.5);
}

Environnement* creer_env(float temp, float hum, float eau, float pcar)
{
    Environnement* new = calloc(sizeof(Environnement), 1);
    new->temp = temp;
    new->hum = hum;
    new->pcar = pcar;
    new->cdom = (int)definir_couleur(temp, hum);
    new->pveg = definir_vegetation(temp,hum);
    new->eau = eau;
    return new;
}


void Afficher_Milieu (Environnement *milieu)
{
    printf("[ENVIRONNEMENT]----------\n");
    printf("Temperature:       %f\n", milieu->temp);
    printf("Humidité:          %f\n", milieu->hum);
    printf("eau:   %f\n", milieu->eau);
    printf("couleur dominante: %x\n", milieu->cdom);
    printf("pourcentate veg:   %f\n", milieu->pveg);
    printf("pourcentage car:   %f\n", milieu->pcar);
    printf("[FIN ENVIRONNEMENT]------\n");
}
