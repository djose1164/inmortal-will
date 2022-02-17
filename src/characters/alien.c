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

Alien *_aliens = NULL;
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

void alien_create(IW_Texture *skin)
{
    Alien *aliens = memory_allocate(sizeof *aliens * ALIEN_MAX_NUM);
    _aliens = aliens;
    for (size_t i = 0; i < ALIEN_MAX_NUM; i++)
        aliens[i] = alien_init(skin);
    return aliens;
}

Alien alien_get_next_one(Alien *aliens)
{
    TraceLog(LOG_INFO, "%s(): getting next alien (if avaible)...", __func__);
    assert(aliens);
    assert(*aliens);
    Alien current = NULL;
    for (size_t i = 0; i < ALIEN_MAX_NUM; i++)
        if (!aliens[i]->super->attacking)
            current = aliens[i];
    if (current)
    {
        puts("## Here");
        current->super->frame->pos.y = (float)GetRandomValue(1, GetScreenHeight());
        TraceLog(LOG_INFO, "%s(): getting next alien (if avaible)... Done!", __func__);
        return current;
    }
    else
        TraceLog(LOG_INFO, "%s(): getting next alien (if avaible)... Failed!", __func__);
    return NULL;
}

void alien_update()
{
    assert(_aliens);
    static Goto _goto;
    static unsigned timer;
    timer++;
    for (size_t i = 0, j = 0; j < ALIEN_MAX_NUM; j++)
    {
        i = GetRandomValue(0, 4);
        float *y = &_aliens[i]->super->frame->pos.y;
        unsigned height = _aliens[i]->super->frame->get_texture_height(_aliens[i]->super->frame);
        if (*y < 1.f)
            _goto = GO_UP;
        if (*y > GetScreenHeight() - height)
            _goto = GO_DOWN;

        switch (_goto)
        {
        case GO_UP:
            *y += TIME(60) * _aliens[i]->super->speed;
            break;

        case GO_DOWN:
            *y -= TIME(60) * _aliens[i]->super->speed;
            break;
        default:
            fprintf(stderr, "Undefined address %s: %s", __FILE__, __LINE__);
            break;
            alien_attack(_aliens[i]);
        }

        _aliens[i]->super->update(_aliens[i]->super);
        if (_aliens[i]->super->destroyed)
            alien_get_next_one(_aliens);
    }
    if (timer >= 500)
    {
        timer = 0;
        alien_get_next_one(_aliens);
    }
}

void alien_draw()
{
    for (size_t i = 0; i < ALIEN_MAX_NUM; i++)
    {
        if (!_aliens[i]->super->destroyed)
        {
            Texture2D skin = *_aliens[i]->super->frame->get_texture(_aliens[i]->super->frame);
            DrawTextureRec(skin, _aliens[i]->super->frame->rectangle, _aliens[i]->super->frame->pos, WHITE);
            _aliens[i]->super->draw_lasers(_aliens[i]->super);
        }
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

Base *alien_get_base(Alien self)
{
    return self->super;
}