#include "main.h"

typedef enum
{
    TESTING,
    GAMEOVER,
    _SCREEN_MANAGER_MAX
} ScreenHandler;

void draw_background(const Frame *self)
{
    static float scrolling = 0.f;
    scrolling -= 1.f;
    const float max = -self->_texture->_texture2D.width * 4.5f;
    if (scrolling <= max)
        scrolling = 0;
    DrawTextureEx(*self->get_texture(self), (Vector2){scrolling, self->pos.y},
                  0.f, 4.5f, WHITE);
    DrawTextureEx(*self->get_texture(self), (Vector2){self->get_texture_width(self) * 4.5f + scrolling, self->pos.y}, 0.f, 4.5f, WHITE);
}

int main(int argc, char const *argv[])
{
    // Windows size.
    const unsigned screenWidth = 1080;
    const unsigned screenHeight = 500;

    // The first thing. Init the window.
    InitWindow(screenWidth, screenHeight, APP_NAME);
    InitAudioDevice();
    SetTargetFPS(60);

    Music music = LoadMusicStream("resources/eon.mp3");
    PlayMusicStream(music);

    Player *player = player_init(texture_init("resources/spaceship-draft.png"));
    enemy = alien_init(texture_init("resources/enemy.png"));

    void *update_arr[] = {
        alien_update,
        player->update,
    };
    void *del_arr[] = {
        alien_del,
        player->del,
    };
    void *draw_arr[] = {
        alien_draw,
        player->draw,
    };
    struct ScreenHandler handler = {
        .update = update_arr,
        .del = del_arr,
        .draw = draw_arr,
    };
    void *frames[] = {enemy, player};
    Frame *background = frame_init(texture_init("./resources/space_with_stars.png"), &(Vector2){0, 0}, &WHITE);
    background->draw = draw_background;
    String *str = string_init("Testing");
    Screen *testing = screen_init(str, player, &background, frames, 2, &manager);
    Screen *gameover = screen_init(string_init("Game Over"), NULL, &background, NULL, 0, NULL);
    Screen *screens[_SCREEN_MANAGER_MAX] = {
        [TESTING] = testing,
        [GAMEOVER] = gameover,
    };
    Screen *current = screens[TESTING];
    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        current->update(current);

        BeginDrawing();
        ClearBackground(BLACK);
        current->render(current);
        EndDrawing();
    }

    //gameover->background = NULL;
    for (size_t i = 0; i < _SCREEN_MANAGER_MAX; i++)
        screens[i]->del(&screens[i]);
    
    UnloadMusicStream(music);
    CloseWindow();
    texture_memstats();
    frame_memstats();
    memory_check_counter();

    return 0;
}
