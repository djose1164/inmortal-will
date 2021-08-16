#ifndef LIVING_H
#define LIVING_H

#include "common_atrrs.h"

struct Living
{
    unsigned age;
    int stamina;
    unsigned vit;   /* The HP has to be proportional to its VIT. */
    unsigned str;   /* The attack has to be proportional to its STR. */
    CommonAtrrs attrs;
    unsigned weight;
};
typedef struct Living Living;

#endif //LIVING_H
