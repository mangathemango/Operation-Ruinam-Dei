#include <player.h>
#include <app.h>

/*
*   This function is called inside App_PostUpdate().
?   It updates the player's input, position, and rendering.
*/
int Player_PostUpdate() {
    Player_Input_Handler();
    //Basically, if the movement is locked, it dash,if not, its handles normally
    if(player.state.dashing) Player_HandleDash();
    else player.state.direction = Vec2_Zero;

    // Only change animation when movement state changes
    static bool wasMoving = false;
    if (player.state.moving != wasMoving) {
        if (player.state.moving) {
            Animation_Play(player.config.animation, "spin");
        } else {
            Animation_Play(player.config.animation, "idle");
        }
        wasMoving = player.state.moving;
    }


    Animation_Update(player.config.animation);
    Player_WrapAroundScreen();
    Player_Render();
    return 0;
}