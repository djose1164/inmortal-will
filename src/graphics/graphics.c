#include "graphics/graphics.h"

void graphics_check_bound_limits(Player *const player)
{
    // Check bounds on x-axis.
    if (player->vector2D.x + player->skin.width >= GetScreenWidth())
        player->vector2D.x = GetScreenWidth() - player->skin.width;
    else if (player->vector2D.x <= 0)
        player->vector2D.x = 0;
    
    // Check bounds on y-axis.
    if (player->vector2D.y + player->skin.height >= GetScreenHeight())
        player->vector2D.y = GetScreenHeight() - player->skin.height;
    else if (player->vector2D.y <= 0)
        player->vector2D.y = 0;
}