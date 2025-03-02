#include <player.h>
#include <app.h>

/*
*   This function is called inside App_PostUpdate().
?   It updates the player's input, position, and rendering.
*/
int Player_PostUpdate() {
    Player_Input_Handler();
    Player_WrapAroundScreen();
    Player_Render();
    return 0;
}