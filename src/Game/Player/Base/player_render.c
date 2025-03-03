#include <player.h>
#include <app.h>

/*
*   Renders the player sprite based on the player's position.
*/
int Player_Render() {
    Animation_Render(player.config.animation, player.state.position, player.config.spriteSize);
    return 0;
}




