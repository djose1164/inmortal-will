#include "characters/alien.h"

#define TIME(v) 60 * (1.f / (v))

typedef enum {GO_DOWN, GO_UP} Goto;

struct Alien
{
    Base *super;
    float speed;
};

Alien alien_init(IW_Texture *skin)
{
    Alien self = memory_allocate(sizeof *self);
    Frame *frame = frame_init(skin, &(Vector2){GetScreenWidth()-256, 100}, &WHITE);
    self->super = base_init("Alien", MONSTER, frame);
    self->speed = 2.5f;

    return self;
}

void alien_update(Alien self)
{
    puts("Alien updating...");
    static Goto _goto;
    float *y = &self->super->frame->position.y;
    unsigned height = self->super->frame->get_texture_height(self->super->frame);
    if (*y + 85 < 1.f)
        _goto = GO_UP;
    if (*y + 86 > GetScreenHeight()-86)
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
    printf("y: %.3f\n", *y);
    puts("Alien updating... Done!");
}

void alien_draw(Alien self)
{
    assert(self);
    DrawText("Alien", 500, 350, 36, RED);
    Texture2D skin = *self->super->frame->get_texture(self->super->frame);
    DrawTextureRec(skin, self->super->frame->rectangle, self->super->frame->position, WHITE);
}

void alien_del(Alien self)
{
    self->super->del(self->super);
    memory_release(self);
}