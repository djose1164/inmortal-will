#ifndef ALIEN_H
#define ALIEN_H

#include "characters/base.h"

typedef struct Alien *Alien;

#define T Alien

extern T enemy;

T alien_init(IW_Texture *skin);

void alien_update(T self);

void alien_draw(T self);

void alien_del(T self);

Rectangle alien_get_rec(T self);

void alien_set_destroy(T self, bool status);

#undef T
#endif //ALIEN_H
