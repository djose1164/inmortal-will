/**
 * @file player.c
 * @author your name (you@domain.com)
 * @brief Defefinition of player.h. All methods that modify or work with player
 * must be here.
 * @version 0.1
 * @date 2021-06-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "characters/player.h"

struct Laser
{
    Vector2 pos;
    double speed;
    unsigned width;
    unsigned height;
    IW_Texture *skin;
    bool launched;
};

LinkedList player_list = {.head = NULL};
static const unsigned multiplier = 4;

#define NUMS_OF_FRAME 2
#define MAX_NUMS_OF_LASER 32
#define LASER_SPEED 5.f

Player *player_init(const Living *living)
{
    puts("Creating player...");
    Player *self = memory_allocate(sizeof *self);
    const unsigned frame_height = living->frame->get_texture_height(living->frame);
    living->frame->rectangle.height = frame_height / NUMS_OF_FRAME;
    self->living_super = living;
    self->laser = weapon_create_lasers(MAX_NUMS_OF_LASER);
    self->attacking = false;
    player_bindfuncs(self);
    puts("Creating player... Done!");
    return self;
}

void player_del(Player *self)
{
    puts("Deleting player...");
    self->living_super->del(self->living_super);
    memory_release(self);
    puts("Deleting player... Done");
}

void player_set_name(Player *const self, const char *name)
{
    //if (!Str_is_valid(name))
    //    memory_die("Introduce a valid name!");
    self->living_super->name = (char *)name;
}

static void player_draw(const Player *self)
{
    self->living_super->draw(self->living_super);
    weapon_draw_lasers(self->laser);
}

static void player_update(Player *const self)
{
    player_handle_input(self);
    if (self->attacking)
        weapon_update_lasers(self->laser);
}

/*****************************************************************************/
/*                                  Private functions:                       */
/*****************************************************************************/

void player_set_texture(Player *self, IW_Texture *texture)
{
    self->living_super->frame->bind_texture(self->living_super->frame, texture);
    puts("Skin loaded!");
}

static void player_bindfuncs(Player *const self)
{
    self->init = player_init;
    self->set_texture = player_set_texture;
    self->set_name = player_set_name;
    self->update = player_update;
    self->draw = player_draw;
    self->del = player_del;
}

static void player_handle_input(Player *const self)
{
    static int counter = 0, current_frame = 1;
    Frame *frame = self->living_super->frame;
    unsigned height = (float)frame->get_texture_height(frame);
    bool condition = IsKeyDown(KEY_A) || IsKeyDown(KEY_D) || IsKeyDown(KEY_W) || IsKeyDown(KEY_S);
    counter++;
    if (condition)
    {
        // if (counter >= GetFPS() / multiplier)
        // {
        //     counter = 0;
        //     current_frame++;
        //     if (current_frame > 2)
        //         current_frame = 1;

        //     frame->rectangle.y = (float)current_frame * (height / 2);
        // }
        frame->rectangle.y = (float)height / 2;
    }
    else
        frame->rectangle.y = 0;

    if (IsKeyDown(KEY_A))
        frame->position.x -= multiplier;
    if (IsKeyDown(KEY_D))
        frame->position.x += multiplier;
    if (IsKeyDown(KEY_W))
        frame->position.y -= multiplier;
    if (IsKeyDown(KEY_S))
        frame->position.y += multiplier;
    if (IsKeyReleased(KEY_J))
        player_attack(self);
    /* Jump stuff. */
}

static void player_handle_laser(const Player *self)
{
    static Laser lasers = NULL;
}

static void player_attack(Player *self)
{
    /*
        Aqui se lanza los lasers.
        El Laser tiene velocidad. Debe ser lanzado dede su punta.
    */
    puts("Launching laser...");
    Laser laser = weapon_next_laser(self->laser);
    if (!laser)
        return;
    laser->launched = true;
    laser->height = self->laser->skin->get_height(self->laser->skin);
    laser->width = self->laser->skin->get_width(self->laser->skin);
    const float y = self->living_super->frame->position.y + 24.5f;
    laser->pos = (Vector2){self->living_super->frame->position.x, y};
    laser->pos.x = self->living_super->frame->rectangle.width + self->living_super->frame->position.x;
    self->attacking = true;
    puts("Launching laser... Done!");
}

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

void weapon_update_lasers(Laser laser)
{
    /*
        El cuando un rayo laser sea tirado y este haya ido mas alla de los limites sera eliminado.
    */
    double time = GetFPS() * (.035f/laser->speed);
    printf("time: %f\n", time);
    size_t lasers_attacking = 0;
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
    {
        if (laser[i].launched)
            laser[i].pos.x += time * laser->speed;
        if (laser[i].pos.x > GetScreenWidth() * 2.f)
            laser[i].launched = false;

    }//printf("laser->pos.x = %.3f\n", laser->pos.x);
}

void weapon_draw_lasers(Laser laser)
{
    for (size_t i = 0; i < MAX_NUMS_OF_LASER; i++)
        if (laser[i].launched)
            DrawTexture(laser[i].skin->_texture2D, laser[i].pos.x, laser[i].pos.y, WHITE);
}