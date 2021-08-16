#include "graphics/graphics.h"

void graphics_check_bound_limits(Player *const player)
{
    // Check bounds on x-axis.
    if (player->pos.x + player->skin.width >= GetScreenWidth())
        player->pos.x = GetScreenWidth() - player->skin.width;
    else if (player->pos.x <= 0)
        player->pos.x = 0;
    
    // Check bounds on y-axis.
    if (player->pos.y + player->skin.height >= GetScreenHeight())
        player->pos.y = GetScreenHeight() - player->skin.height;
    else if (player->pos.y <= 0)
        player->pos.y = 0;
}