#include "characters/alien.h"
#include "core/memory_p.h"
#include <assert.h>
#include <stdio.h>

#define TIME(v) 60 * (1.f / (v))
#define ALIEN_SPEED 2.5f
typedef enum
{
    GO_DOWN,
    GO_UP
} Goto;

Alien enemy = NULL;
struct Alien
{
    Base *super;
    float speed;
    bool destroyed;
    Laser *lasers;
};

static inline void alien_attack(restrict Alien self)
{
    if ((long)GetTime() % 5 == 0)
        weapon_next_laser(*self->lasers, &self->super->frame->pos);
}

Alien alien_init(IW_Texture *skin)
{
    Alien self = memory_allocate(sizeof *self);
    Frame *frame = frame_init(skin, &(Vector2){GetScreenWidth() - 256, 100}, &WHITE);
    self->super = base_init("Alien", MONSTER, frame);
    self->speed = ALIEN_SPEED;
    self->destroyed = false;
    (*self->lasers) = weapon_create_lasers(MAX_NUMS_OF_LASER);

    return self;
}

void alien_update(Alien self)
{
    static Goto _goto;
    float *y = &self->super->frame->pos.y;
    unsigned height = self->super->frame->get_texture_height(self->super->frame);
    if (*y < 1.f)
        _goto = GO_UP;
    if (*y > GetScreenHeight() - height)
        _goto = GO_DOWN;

    switch (_goto)
    {
    case GO_UP:
        *y += TIME(60) * self->speed;
        break;

    case GO_DOWN:
        *y -= TIME(60) * self->speed;
        break;
    default:
        fprintf(stderr, "Undefined address %s: %s", __FILE__, __LINE__);
        break;
    }

    alien_attack(self);
    weapon_update_lasers(*self->lasers);
}

void alien_draw(Alien self)
{
    DrawText("Alien", 500, 350, 36, RED);
    if (!self->destroyed)
    {
        Texture2D skin = *self->super->frame->get_texture(self->super->frame);
        DrawTextureRec(skin, self->super->frame->rectangle, self->super->frame->pos, WHITE);
        self->super->draw_lasers(self->super);
    }
}

void alien_del(Alien *self)
{
    puts("Deleting alien...");
    assert(self);
    assert(*self);
    weapon_destroy_all(*(*self)->lasers);
    (*self)->super->del(&(*self)->super);
    memory_release(self);
    puts("Deleting alien... Done!");
}

void alien_set_destroy(Alien self, bool status)
{
    self->destroyed = status;
}

bool alien_get_destroyed(Alien self)
{
    return self->destroyed;
}

Rectangle alien_get_rec(Alien self)
{
    return (Rectangle){
        .height = self->super->frame->rectangle.height,
        .width = self->super->frame->rectangle.width,
        .x = self->super->frame->pos.x,
        .y = self->super->frame->pos.y,
    };
}
