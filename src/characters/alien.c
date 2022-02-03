#include "characters/alien.h"

struct Alien
{
    Base *super;
};

Alien alien_init(IW_Texture *skin)
{
    Alien self = memory_allocate(sizeof *self);
    Frame *frame = frame_init(texture_init(skin), &(Vector2){50, 100}, &WHITE);
    self->super = base_init("Alien", MONSTER, frame);
}

void alien_update(Alien self)
{
    float *x = &self->super->frame->position.x;
    float *y = &self->super->frame->position.y;
    if (*x < 1.f)
        *x++;
    else if (*x > (float)GetScreenWidth() * 1.5)
        *x--;
    if (*y < 1.f)
        *y++;
    else if (*y > GetScreenHeight()-200)
        *y--;
    self->super->update(self->super);
}

void alien_draw(Alien self)
{
    self->super->draw(self->super);
}