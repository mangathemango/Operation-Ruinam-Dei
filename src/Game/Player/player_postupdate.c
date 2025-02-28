#include <player.h>
#include <app.h>

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

int Player_PostUpdate() {
    Player_Input_Handler();
    Player_Post_Position();
    Player_Render();
    return 0;
}