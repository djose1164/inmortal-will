#ifndef ALIEN_H
#define ALIEN_H

#include "characters/base.h"

typedef struct Alien *Alien;

#define T Alien

extern T enemy;

T alien_init(IW_Texture *skin);

T alien_get_next_one(T *aliens);

void alien_update(T self);

void alien_draw(T self);

void alien_del(T *self);

Rectangle alien_get_rec(T self);

void alien_set_destroy(T self, bool status);

bool alien_get_destroyed(T self);

#undef T
#endif //ALIEN_H
