#include "weapon/laser.h"
#include "characters/alien.h"
#include "core/memory_p.h"
#include "core/screen.h"
#include <stdio.h>
#include <assert.h>

struct Laser
{
    double speed;
    IW_Texture **skin;
    Frame *frame;
    bool launched;
    Owner owner;
    Sound *sound;
};

static size_t created_lasers;
static size_t deallocated_lasers;

Laser laser_create_lasers(unsigned quantity, Owner owner)
{
    puts("Creating lasers...");
    struct Laser *lasers = memory_allocate(sizeof *lasers * MAX_NUMS_OF_LASER);
    static IW_Texture *skin = NULL;
    static Sound sound;
    if (!skin)
    {
        skin = texture_init("resources/laser-beam.png");
        sound = LoadSound("resources/laser_sound.ogg");
        SetSoundVolume(sound, .6f);
    }
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
    {
        lasers[i].skin = &skin;
        lasers[i].launched = false;
        lasers[i].speed = LASER_SPEED;
        lasers[i].owner = owner;
        lasers[i].sound = &sound;
    }
    puts("Creating lasers... Done!");
    return lasers;
}

void laser_check_impact(Laser laser, Rectangle *target)
{
    assert(laser);
    assert(laser->frame);
    Rectangle rec = {
        .height = laser->frame->rectangle.height,
        .width = laser->frame->rectangle.width,
        .x = laser->frame->pos.x,
        .y = laser->frame->pos.y,
    };
    return CheckCollisionRecs(rec, *target);
/*
    Frame _ = *global_player->base_super->frame;
    Rectangle prec = {
        .height = _.rectangle.height,
        .width = _.rectangle.width,
        .x = _.pos.x,
        .y = _.pos.y,
    };

    bool player_hit = CheckCollisionRecs(rec, alien_get_rec(enemy)) && laser->owner == PLAYER;
    bool alien_hit = CheckCollisionRecs(rec, prec) && laser->owner == MONSTER;

    if (player_hit)
    {
        TraceLog(LOG_DEBUG, "%s", "/-/-/-/-/-/-/Player hit!/-/-/-/-/-/-/-/-");
        *screen_manager = screens[SCREEN_WIN];
    }
    if (alien_hit)
    {
        TraceLog(LOG_DEBUG, "%s", "/-/-/-/-/-/-/Alien hit!/-/-/-/-/-/-/-/-");
        *screen_manager = screens[SCREEN_GAMEOVER];
        //    alien_set_destroy(enemy, true);
    }*/
}

Laser laser_next_laser(Laser laser, Vector2 *pos)
{
    Laser current = NULL;
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
    {
        if (!laser[i].launched)
        {
            current = &laser[i];
            break;
        }
    }
    if (current)
    {
        current->frame = frame_init(*current->skin, pos, &WHITE);
        current->frame->pos.y += (*current->skin)->get_width((*current->skin))/1.5;
        current->frame->rectangle.height;
        current->launched = true;
        PlaySound(*current->sound);
        created_lasers++;
        return current;
    }
    puts("No laser avaible!!!");
    return NULL;
}

static void laser_destroy(Laser laser)
{
    laser->launched = false;
    frame_del_without_texture(&laser->frame);
    deallocated_lasers++;
}

void laser_destroy_all(Laser laser, bool restart)
{
    if (*laser->skin && !restart)
    {
        (*laser->skin)->del(laser->skin);
        UnloadSound(*laser->sound);
    }
    while (laser_is_attacking(laser))
        for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
            if (laser[i].launched)
                laser_destroy(&laser[i]);

    if (deallocated_lasers == created_lasers)
        puts("Mem in lasers is Ok!");
    else
        printf("Mem in lasers is NOT Ok!\n"
               "Allocated: %zu \t Deallocated: %zu\n",
               created_lasers, deallocated_lasers);
}

void laser_update_lasers(Laser laser)
{
    /*
        El cuando un rayo laser sea tirado y este haya ido mas alla de los limites sera eliminado.
    */
    volatile double time = GetFrameTime();
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
    {
        if (laser[i].launched)
        {
            laser_check_impact(&laser[i]);
            switch (laser[i].owner)
            {
            case PLAYER:
                laser[i].frame->pos.x += time * laser->speed;
                TraceLog(LOG_DEBUG, "Player's laser's x: %.f", laser[i].frame->pos.x);
                break;

            case MONSTER:
                laser[i].frame->pos.x -= time * laser->speed;
                TraceLog(LOG_DEBUG, "Alien's laser's x: %.f", laser[i].frame->pos.x);
                break;
            }
            if (laser[i].frame->pos.x > GetScreenWidth() * 1.5 || laser[i].frame->pos.x + laser[i].frame->get_texture_width(laser[i].frame) < 1)
                laser_destroy(&laser[i]);
        }
    }
}

void laser_draw_lasers(Laser laser)
{
    float degrees = 0;
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
    {
        if (laser[i].launched)
        {
            if (laser[i].owner == MONSTER)
                degrees = 180.f;
            DrawTextureEx(
                (*laser[i].skin)->_texture2D,
                laser[i].frame->pos,
                degrees,
                1.f,
                WHITE);
        }
    }
}

const IW_Texture *laser_get_texture(Laser laser)
{
    return *laser->skin;
}

void laser_set_frame(Laser laser, Frame *frame)
{
    laser->frame = frame;
}

void laser_set_lauched(Laser laser, bool launched)
{
    laser->launched = launched;
}

void laser_set_pos(Laser laser, Vector2 *pos)
{
    laser->frame->rectangle.x = pos->x;
    laser->frame->rectangle.y = pos->y;
}

bool laser_is_attacking(Laser laser)
{
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
    {
        if (laser[i].launched)
            return true;
    }
    return false;
}
