#include "item/weapon.h"
#include "characters/alien.h"
#include <stdio.h>
#include <assert.h>

struct Laser
{
    double speed;
    IW_Texture *skin;
    Frame *frame;
    bool launched;
    LaserDirection direction;
};

static size_t created_lasers;
static size_t deallocated_lasers;

Laser weapon_create_lasers(unsigned quantity, LaserDirection direction)
{
    puts("Creating lasers...");
    static struct Laser lasers[MAX_NUMS_OF_LASER] = {0};
    static IW_Texture *skin = NULL;
    if (!skin)
        skin = texture_init("resources/laser.png");

    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
    {
        lasers[i].skin = skin;
        lasers[i].launched = false;
        lasers[i].speed = LASER_SPEED;
        lasers[i].direction = direction;
    }
    puts("Creating lasers... Done!");
    return &lasers;
}

void weapon_check_impact(Laser laser)
{
    assert(laser);
    assert(laser->frame);
    Rectangle reclaser = {
        .height = laser->frame->rectangle.height - 10,
        .width = laser->frame->rectangle.width,
        .x = laser->frame->pos.x,
        .y = laser->frame->pos.y,
    };

    bool collision = CheckCollisionRecs(reclaser, alien_get_rec(enemy));
    if (collision)
        alien_set_destroy(enemy, true);
    
}

Laser weapon_next_laser(Laser laser, Vector2 *pos)
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
        current->frame = frame_init(current->skin, pos, &WHITE);
        current->launched = true;
        created_lasers++;
        return current;
    }
    puts("No laser avaible!!!");
    return NULL;
}

static void weapon_laser_destroy(Laser laser)
{
    laser->launched = false;
    frame_del_without_texture(&laser->frame);
    deallocated_lasers++;
}

void weapon_destroy_all(Laser laser)
{
    if (laser->skin)
        laser->skin->del(&laser->skin);
    while (weapon_is_laser_attacking(laser))
        for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
            if (laser[i].launched)
                weapon_laser_destroy(&laser[i]);
        
    
    if (deallocated_lasers == created_lasers)
        puts("Mem in lasers is Ok!");
    else
        printf("Mem in lasers is NOT Ok!\n"
               "Allocated: %zu \t Deallocated: %zu\n",
               created_lasers, deallocated_lasers);
}

void weapon_update_lasers(Laser laser)
{
    /*
        El cuando un rayo laser sea tirado y este haya ido mas alla de los limites sera eliminado.
    */
    weapon_check_impact(laser);
    volatile double time = 60 * (.035f / laser->speed);
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
    {
        if (laser[i].launched)
        {
            laser[i].frame->pos.x += time * laser->speed;
            if (laser[i].frame->pos.x > GetScreenWidth() * 1.5)
                weapon_laser_destroy(&laser[i]);
        }
    }
}

void weapon_draw_lasers(Laser laser)
{
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
        if (laser[i].launched)
            DrawTextureRec(laser[i].skin->_texture2D, laser[i].frame->rectangle,
                           laser[i].frame->pos, WHITE);
}

const IW_Texture *weapon_get_texture(Laser laser)
{
    return laser->skin;
}

void weapon_set_frame(Laser laser, Frame *frame)
{
    laser->frame = frame;
}

void weapon_set_lauched(Laser laser, bool launched)
{
    laser->launched = launched;
}

void weapon_set_pos(Laser laser, Vector2 *pos)
{
    laser->frame->rectangle.x = pos->x;
    laser->frame->rectangle.y = pos->y;
}

bool weapon_is_laser_attacking(Laser laser)
{
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
    {
        if (laser[i].launched)
            return true;
    }
    return false;
}
