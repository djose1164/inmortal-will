#ifndef LIVING_H
#define LIVING_H

#include "common_atrrs.h"

typedef struct Living Living;
struct Living
{
    unsigned age;
    int stamina;
    unsigned vit;   /* The HP has to be proportional to its VIT. */
    unsigned str;   /* The attack has to be proportional to its STR. */
    CommonAtrrs attrs;
};


#endif //LIVING_H
