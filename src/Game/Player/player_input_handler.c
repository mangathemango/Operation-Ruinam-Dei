#include <player.h>
#include <input.h>

void Player_Input_Handler() {
    if (Input->keyboard.keys[SDL_SCANCODE_LSHIFT].pressed) Player_Dash(Vec2_Up);
    if (Input->keyboard.keys[SDL_SCANCODE_W].held) Player_Move(Vec2_Up);
    if (Input->keyboard.keys[SDL_SCANCODE_A].held) Player_Move(Vec2_Left);
    if (Input->keyboard.keys[SDL_SCANCODE_S].held) Player_Move(Vec2_Down);
    if (Input->keyboard.keys[SDL_SCANCODE_D].held) Player_Move(Vec2_Right);
}