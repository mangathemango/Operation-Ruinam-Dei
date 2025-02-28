#include <player.h>
#include <input.h>


const int UP = 1;
const int LEFT = 2;
const int DOWN = 3;
const int RIGHT = 4;

int Timer = 0;
int direction = 0;
int Cooldown = 0;

void Dash(int DashTimer)
{
    if(DashTimer <= 0) player.config.speed = 1;
    else player.config.speed = 5;
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

int DashCooldown(int Cooldown)
{
    if(Cooldown > 0) return 1;
    return 0;
}

void Player_Input_Handler() {

    Dash(Timer);
    if (Input->keyboard.keys[SDL_SCANCODE_LSHIFT].pressed && Timer <= 0)
    {
        if(Cooldown <= 0)
        {
            Timer += 25;
        }
        if(Cooldown <= 0) Cooldown = 100;

    }
    if (Input->keyboard.keys[SDL_SCANCODE_W].held) Player_Move(Vec2_Up), direction = UP;
    if (Input->keyboard.keys[SDL_SCANCODE_A].held) Player_Move(Vec2_Left), direction = LEFT;
    if (Input->keyboard.keys[SDL_SCANCODE_S].held) Player_Move(Vec2_Down), direction = DOWN;
    if (Input->keyboard.keys[SDL_SCANCODE_D].held) Player_Move(Vec2_Right), direction = RIGHT;


    Cooldown--;
    if(Timer > 0)
    {
        Timer--;
        DashMovementLock(direction); 
    };
}