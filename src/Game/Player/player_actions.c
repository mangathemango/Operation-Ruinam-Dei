#include <player.h>
#include <time_system.h>
#include <timer.h>

int Player_Move(Vec2 direction) {
    if (Vec2_Magnitude(direction) == 0) return 0;
    
    player.state.position.x += direction.x * (player.config.speed * Time->deltaTimeSeconds);
    player.state.position.y += direction.y * (player.config.speed * Time->deltaTimeSeconds);

    
    return 0;
}

int Player_Dash(Vec2 direction) {
    static Timer* dashCooldown = NULL;

    if (dashCooldown != NULL) {
        if (!Timer_IsFinished(dashCooldown)) return 0;
        else {
            Timer_Destroy(dashCooldown);
            dashCooldown = NULL;
        }
    }

    if (Vec2_Magnitude(direction) == 0) return 0;
    
    player.state.position.x += direction.x * (player.config.speed * Time->deltaTimeSeconds * 20);
    player.state.position.y += direction.y * (player.config.speed * Time->deltaTimeSeconds * 20);

    dashCooldown = Timer_Create(1);
    Timer_Start(dashCooldown);
    return 0;
}