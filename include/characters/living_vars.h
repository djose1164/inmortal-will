#ifndef LIVING_VARS_H
#define LIVING_VARS_H

#include "core/object.h"
#include "graphics/frame.h"

struct _BaseStats
{
    /** Base stats. */
    int stamina;
    int vit;      /* The HP has to be proportional to its VIT. */
    unsigned str; /* The attack has to be proportional to its STR. */
    unsigned age;
    unsigned agi;
};

struct _DerivedStats
{
    /** Derived stats. */
    unsigned defense; /* Current defense. */
    unsigned attack;
    unsigned weight;
    unsigned height;
    unsigned speed;
};

typedef struct Living Living;
struct Living
{
    Object *object_super;
    char *name; /* Name (the nicksame has to be saved here). */
    struct _BaseStats base_stats;
    struct _DerivedStats derived_stats;
    Frame *frame;
    /* Current level. */
    unsigned lvl;
    bool magic;

    void (*del)(Living *self);
    void (*draw)(const Living *self);
};

#endif //LIVING_VARS_H
