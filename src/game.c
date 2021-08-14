#include "include/game.h"

static const char *professions[] = {"Warrior", "Wizard"};

void game_start()
{
    // Set
    //Player *player = Player_init(player);
    // Text input
    TextInput txt_inpt;
    textInput_init(&txt_inpt, screenWidth/3, screenHeight/3, 300, 150);
    // Starting the game. Show a message asking to fill in.
    DrawText("Set a nickname..", screenWidth/2, screenHeight/4, 28, RED);
    textInput_draw(&txt_inpt);
    DrawText("Hola", (screenWidth/3) + 5, (screenHeight/3) + 3, 26, RED);
    //game_set_player_name(player);
    //set_profession(player);

    //memory_release(player->living.name);
    //memory_release(player);
    //printf("Allocated: %zu\t Deallocated: %zu\n", memory_get_allocated_counter(),
    //       memory_get_released_counter());
}
#if 0
static void game_set_player_name(Player *self)
{
    char line[50];
    char *name = 0L;

    printf("Enter a name(not greater than 50 letters): ");
    fgets(line, sizeof(line), stdin);
    line[strlen(line) - 1] = '\0';

    name = memory_allocate(name, sizeof(line));
    strncpy(name, line, sizeof(name));
    self->object.name = name;
}

static void set_profession(Player *const self)
{
    char line[sizeof(unsigned short)];
    const char *profession;
    unsigned short chose;

    printf("Select your profession!\n"
           "1) Warrior.\n"
           "2) Wizard.\n"
           "\aOption: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%hu", &chose);

    //profession_option_is_valid(chose);

    self->profession = (char *)professions[chose - 1];
}

static bool profession_option_is_valid(unsigned option)
{
    switch (option)
    {
    case 1:
        //TODO: Some stuff for this.
        break;
    case 2:
        //TODO: Some stuff here too.
        break;

    default:
        printf("Invalid option!");
        break;
    }

    return 0;
}
#endif