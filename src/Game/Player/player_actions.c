#include <player.h>


const int DASH_DURATION = 100;
const int COOLDOWN = 25;
int direction = 0;
int Cooldown = 0;


int Player_Move(Vec2 direction) {
    if (Vec2_Magnitude(direction) == 0) return 0;
    
    player.state.position.x += direction.x * player.config.speed;
    player.state.position.y += direction.y * player.config.speed;
    return 0;
}

void DashMovementLock(int direction)
{
    if(direction == UP)
        {
            Player_Move(Vec2_Up);
        }
    if(direction == LEFT)
        {
            Player_Move(Vec2_Left);
        }
    if(direction == DOWN)
        {
            Player_Move(Vec2_Down);
        }
    if(direction == RIGHT)
        {
            Player_Move(Vec2_Right);
        }  
}

int Dash(Direction direction)
{

    Cooldown = 100;
    if(DashTimer < 0) player.config.speed = 1;
    else player.config.speed = 5;
    
    DashMovementLock(direction);
}