#include <player.h>
#include <time_system.h>
#include <timer.h>

/*
*   Dash the player in a direction.
?   @param direction The direction to dash the player in.
    TODO: Normalize direction before dashing the player.
    TODO: Use Vec2_Multiply and Vec2_Add instead of multiplying the x and y values manually.
*/

int dashCooldown()
{
    // TODO: WORK IN PROGRESS
    /*dashing();

    static Timer* dashCooldown = NULL;

    if (dashCooldown != NULL) {
        if (!Timer_IsFinished(dashCooldown)) return 0;
        else {
            Timer_Destroy(dashCooldown);
            dashCooldown = NULL;
        }
    }
    

    dashCooldown = Timer_Create(1);
    Timer_Start(dashCooldown);
    return 0;
    */
}

int dashing()
{
    static Timer* movementDuration = NULL;

    if (movementDuration != NULL) {
        if (!Timer_IsFinished(movementDuration))
        {
            Vec2_Normalize(player.state.direction); //Becauset

            player.config.speed = 1000;//Change speed
            player.state.position.x += (player.state.direction.x) * (player.config.speed * Time->deltaTimeSeconds);
            player.state.position.y += (player.state.direction.y) * (player.config.speed * Time->deltaTimeSeconds);

            return 0;
        }
        else {
            Timer_Destroy(movementDuration);
            movementDuration = NULL;
            player.state.movementLocked = false; //Just unchecks movementlock
            player.config.speed = 100; //Revert the speed
            ResetDirection(); //Reset the direction into 0, 0 
            return 1; // the program needs to end here after the movement is done. I dont remember if i still need it but in the previous iteration i need this.
        }
    }

    movementDuration = Timer_Create(0.1);
    Timer_Start(movementDuration);
    return 0;
}
