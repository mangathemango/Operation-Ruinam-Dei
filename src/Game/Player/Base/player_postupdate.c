#include <player.h>
#include <app.h>

/*
*   This function is called inside App_PostUpdate().
?   It updates the player's input, position, and rendering.
*/
int Player_PostUpdate() {
    if(player.state.movementLocked == true)//Basically, if the movement is locked, it dash,if not, its handles normally
    {
        dashing();
    }
    else
    {
        ResetDirection();
        Player_Input_Handler();
    }
    Animation_Update(player.config.animation);
    Player_WrapAroundScreen();
    Player_Render();
    return 0;
}