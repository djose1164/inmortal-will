#include "item/weapon.h"
#include "characters/alien.h"

struct Laser
{
    double speed;
    IW_Texture *skin;
    Frame *frame;
    bool launched;
};

Laser weapon_create_lasers(unsigned quantity)
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
    }
    puts("Creating lasers... Done!");
    return &lasers;
}

void weapon_check_impact(Laser laser)
{
    bool collision = CheckCollisionRecs(laser->frame->rectangle, alien_get_rec(enemy));
    if (collision)
    {
        weapon_set_lauched(laser, false);
        alien_set_destroy(laser, true);
    }
}

Laser weapon_next_laser(Laser laser, Vector2 *pos)
{
    Laser current = NULL;
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
        if (!laser[i].launched)
            current = &laser[i];
    if (current)
    {
        current->frame = frame_init(weapon_get_texture(current), pos, &WHITE);
        current->launched = true;
        return current;
    }
    puts("No laser avaible!!!");
    return NULL;
}

void weapon_laser_destroy(Laser laser)
{
    laser->launched = false;
    laser->frame->del(laser->frame, false);
}

void weapon_update_lasers(Laser laser)
{
    /*
        El cuando un rayo laser sea tirado y este haya ido mas alla de los limites sera eliminado.
    */
    puts("Updating lasers...");
    weapon_check_impact(laser);
    puts("## Here");
    double time = 60 * (.035f / laser->speed);
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
    {
        if (laser[i].launched)
        {
            laser[i].frame->pos.x += time * laser->speed;
            if (laser[i].frame->pos.x > GetScreenWidth())
                weapon_laser_destroy(&laser[i]);
        }
    } // printf("laser->pos.x = %.3f\n", laser->pos.x);
    puts("Updating lasers... Done!");
}

void weapon_draw_lasers(Laser laser)
{
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
    {
        if (laser[i].launched)
        {
            puts("Drawing lasers...");
            DrawTextureRec(laser[i].skin->_texture2D, laser[i].frame->rectangle,
                           laser->frame->pos, WHITE);
            puts("Drawing lasers... Done!");
        }
    }
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