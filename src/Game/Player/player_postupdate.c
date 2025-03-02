#include <player.h>
#include <app.h>

/* 
*   Teleport the player to the other side of the screen if they go off-screen.
!   This is just for temporary player movement debugging, and will be removed later.
*/
void Player_Post_Position()
{
    //This is the logic for the player to wrap around the screen.
    if (player.state.position.x >= app.config.screen_width) {
        player.state.position.x = 0;
    }
    else if (player.state.position.x <= 0) {
        player.state.position.x = app.config.screen_width;
    }
    if (player.state.position.y >= app.config.screen_height) {
        player.state.position.y = -10; //Because the height should come from below 0
    }
    else if (player.state.position.y <= -10) {
        player.state.position.y = app.config.screen_height;
    }
}

/*
*   This function is called inside App_PostUpdate().
?   It updates the player's input, position, and rendering.
*/
int Player_PostUpdate() {
    Player_Input_Handler();
    Player_Post_Position();
    Player_Render();
    return 0;
}