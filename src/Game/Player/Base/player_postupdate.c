#include <player.h>
#include <app.h>

/*
*   This function is called inside App_PostUpdate().
?   It updates the player's input, position, and rendering.
*/
int Player_PostUpdate() {
    Player_Input_Handler();
    Animation_Update(player.config.animation);
    Player_Render();
    return 0;
}