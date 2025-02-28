#include <player.h>

int Player_Move(Vec2 direction) {
    if (Vec2_Magnitude(direction) == 0) return 0;
    
    player.state.position.x += direction.x * player.config.speed;
    player.state.position.y += direction.y * player.config.speed;
    return 0;
}