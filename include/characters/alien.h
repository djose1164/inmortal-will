#ifndef ALIEN_H
#define ALIEN_H

#include "characters/base.h"

typedef struct Alien *Alien;

#define T Alien

T alien_init(IW_Texture skin);

void alien_update(T self);

void alien_draw(T self);

void alien_del(T self);


#undef T
#endif //ALIEN_H
