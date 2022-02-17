#include "characters/alien.h"
#include "core/memory_p.h"
#include <assert.h>
#include <stdio.h>

#define TIME(v) (60 * (1.f / (v)))
#define ALIEN_SPEED 2.5
#define ALIEN_MAX_NUM 5
typedef enum
{
    GO_DOWN,
    GO_UP
} Goto;

Alien enemy = NULL;
struct Alien
{
    Base *super;
};

static inline void alien_attack(restrict Alien self)
{
    static long time;
    if (time > 300)
    {
        time = 0;
        self->super->attack(self->super);
        puts("Alien attacking!!!");
    }
    time++;
}

Alien alien_init(IW_Texture *skin)
{
    Alien self = memory_allocate(sizeof *self);
    self->super = base_init(
        MONSTER,
        frame_init(
            skin,
            &(Vector2){
                GetScreenWidth() - 256, 100},
            &WHITE),
        ALIEN_SPEED);
    self->super->destroyed = false;
    return self;
}

Alien alien_create(IW_Texture *skin)
{
    Alien *aliens = memory_allocate(sizeof *aliens * ALIEN_MAX_NUM);
    for (size_t i = 0; i < ALIEN_MAX_NUM; i++)
        aliens[i] = alien_init(skin);
    return aliens;
}

Alien alien_get_next_one(Alien *aliens)
{
    Alien current = NULL;
    for (size_t i = 0; i < ALIEN_MAX_NUM; i++)
        if (!aliens[i]->super->attacking)
            current =  aliens[i];
    if (current)
        current->super->frame->pos.x = (float)GetRandomValue(1, GetScreenHeight());
    
    return NULL;
}

void alien_update(Alien self)
{
    assert(self);
    assert(self->super);
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
        *y += TIME(60) * self->super->speed;
        break;

    case GO_DOWN:
        *y -= TIME(60) * self->super->speed;
        break;
    default:
        fprintf(stderr, "Undefined address %s: %s", __FILE__, __LINE__);
        break;
    }

    alien_attack(self);
    self->super->update(self->super);
    puts("## Inside");
    if (self->super->destroyed)
        ;
}

void alien_draw(Alien self)
{
    DrawText("Alien", 500, 350, 36, RED);
    if (!self->super->destroyed)
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
    (*self)->super->del(&(*self)->super);
    memory_release(self);
    puts("Deleting alien... Done!");
}

void alien_set_destroy(Alien self, bool status)
{
    self->super->destroyed = status;
}

bool alien_get_destroyed(Alien self)
{
    return self->super->destroyed;
}

Rectangle alien_get_rec(Alien self)
{
    return self->super->get_rec(self->super);
}
