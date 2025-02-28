#include <player.h>


int Player_PostUpdate() {
    Player_Input_Handler();
    Player_Render();
    return 0;
}