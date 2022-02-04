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
    assert(laser);
    assert(laser->frame);
    Rectangle reclaser = {
        .height = laser->frame->rectangle.height,
        .width = laser->frame->rectangle.width,
        .x = laser->frame->pos.x,
        .y = laser->frame->pos.y,
    };

    bool collision = CheckCollisionRecs(reclaser, alien_get_rec(enemy));
    if (collision)
    {
        laser->launched = false;
        alien_set_destroy(enemy, true);
    }
}

Laser weapon_next_laser(Laser laser, Vector2 *pos)
{
    Laser current = NULL;
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
    {
        if (!laser[i].launched)
        {
            current = &laser[i];
            printf("---->i: %zu<-----\n", i);
            break;
        }
    }
    if (current)
    {
        current->frame = frame_init(current->skin, pos, &WHITE);
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
    weapon_check_impact(laser);
    assert(laser);
    volatile double time = 60 * (.035f / laser->speed);
    printf("laser's speed: %.3f\n", laser->speed);
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
    {
        if (laser[i].launched)
        {
            laser[i].frame->pos.x += time * laser->speed;
            if (laser[i].frame->pos.x > GetScreenWidth() * 1.5)
                weapon_laser_destroy(&laser[i]);
        }
    }
    printf("laser->pos.y = %.3f\n", laser->frame->pos.y);
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