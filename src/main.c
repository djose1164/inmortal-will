#include "main.h"

void draw_background(const Frame *self)
{
    static float scrolling = 0.f;
    scrolling -= 1.f;
    const float max = -self->_texture->_texture2D.width * 4.5f;
    if (scrolling <= max)
        scrolling = 0;
    DrawTextureEx(*self->get_texture(self), (Vector2){scrolling, self->position.y},
                  0.f, 4.5f, WHITE);
    DrawTextureEx(*self->get_texture(self), (Vector2){self->get_texture_width(self) * 4.5f 
                  + scrolling, self->position.y}, 0.f, 4.5f, WHITE);
}

int main(int argc, char const *argv[])
{
    // Windows size.
    const unsigned screenWidth = 1080;
    const unsigned screenHeight = 500;

    // The first thing. Init the window.
    InitWindow(screenWidth, screenHeight, APP_NAME);
    SetTargetFPS(60);

    IW_Texture *texture = texture_init("resources/spaceship-draft.png");
    Player *player = player_init(texture);
    Alien *alien = alien_init(texture_init("resources/enemy.png"));            
        
    void *update_arr[] = {player->update, alien_update};
    void *del_arr[] = {player->del, alien_del};
    void *draw_arr[] = {player->draw, alien_draw};
    struct ScreenManager manager = {
        .update = update_arr,
        .del = del_arr,
        .draw = draw_arr,
    };
    void *frames[] = {player, alien};
    Frame *background = frame_init(texture_init("./resources/space_with_stars.png"), &(Vector2){0, 0}, &WHITE);
    background->draw = draw_background;
    Screen *current = screen_init(string_init("Testing"), player, background, frames, 2,&manager);
    current->objcs = (void **){&player, &alien};
    while (!WindowShouldClose())
    {
        current->update(current);
        BeginDrawing();
        ClearBackground(BLACK);
        current->render(current);
        EndDrawing();
    }

    current->del(current);
    CloseWindow();
    memory_check_counter();
    return 0;
}
