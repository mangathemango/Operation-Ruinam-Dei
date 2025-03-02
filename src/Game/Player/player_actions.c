#include <player.h>
#include <time_system.h>

int Player_Move(Vec2 direction) {
    if (Vec2_Magnitude(direction) == 0) return 0;
    
    player.state.position.x += direction.x * (player.config.speed * Time->deltaTimeSeconds);
    player.state.position.y += direction.y * (player.config.speed * Time->deltaTimeSeconds);

    SDL_Log("Moved player by %f * %f * %f = %f", direction.x, player.config.speed, Time->deltaTimeSeconds,direction.x * (player.config.speed * Time->deltaTimeSeconds));
    return 0;
}