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
    if(player.state.movementLocked == false)// ! DONT USE ELSE, CAUSE I IF THE DASHING IS IN COOLDOWN, THE MOVEMENT GETS UNLOCKED
    {
        ResetDirection();
        Player_Input_Handler();
    }
    Animation_Update(player.config.animation);
    Player_WrapAroundScreen();
    Player_Render();
    return 0;
}