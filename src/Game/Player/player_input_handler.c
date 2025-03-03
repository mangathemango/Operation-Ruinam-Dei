#include <player.h>
#include <input.h>

int CurrentDirection = 0;

void Player_Input_Handler() {
    
    if (Input->keyboard.keys[SDL_SCANCODE_LSHIFT].pressed)
    {
        Dash(CurrentDirection);
    }
    if (Input->keyboard.keys[SDL_SCANCODE_W].held) Player_Move(Vec2_Up), direction.CurrentDirection = direction.directionValue.UP;
    if (Input->keyboard.keys[SDL_SCANCODE_A].held) Player_Move(Vec2_Left), Direction.direction.LEFT;
    if (Input->keyboard.keys[SDL_SCANCODE_S].held) Player_Move(Vec2_Down), Direction.direction.DOWN;
    if (Input->keyboard.keys[SDL_SCANCODE_D].held) Player_Move(Vec2_Right), Direction.direction.UP;


}