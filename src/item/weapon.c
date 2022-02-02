#include "item/weapon.h"

struct Laser
{
    Vector2 pos;
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


Laser weapon_next_laser(Laser laser)
{
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
        if (!laser[i].launched)
            return &laser[i];
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
    double time = 60 * (.035f / laser->speed);
    size_t lasers_attacking = 0;
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
    {
        if (laser[i].launched)
        {
            laser[i].pos.x += time * laser->speed;
            if (laser[i].pos.x > GetScreenWidth())
                weapon_laser_destroy(&laser[i]);
        }
    } //printf("laser->pos.x = %.3f\n", laser->pos.x);
}

void weapon_draw_lasers(Laser laser)
{
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
        if (laser[i].launched)
            DrawTextureRec(laser[i].skin->_texture2D, laser[i].frame->rectangle, laser[i].pos, WHITE);
}