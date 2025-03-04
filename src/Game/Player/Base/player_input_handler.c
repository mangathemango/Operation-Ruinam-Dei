#include <player.h>
#include <input.h>

/*
*   This function handles the player's input.
*/
void Player_Input_Handler() {
    //! This dashing kinda sucks right now, but don't worry, it'll be fixed later.
    if (Input->keyboard.keys[SDL_SCANCODE_W].held) Player_Move(Vec2_Up), player.state.direction = Vec2_Add(Vec2_Up,player.state.direction);
    if (Input->keyboard.keys[SDL_SCANCODE_A].held) Player_Move(Vec2_Left), player.state.direction = Vec2_Add(Vec2_Left,player.state.direction);
    if (Input->keyboard.keys[SDL_SCANCODE_S].held) Player_Move(Vec2_Down), player.state.direction = Vec2_Add(Vec2_Down,player.state.direction);
    if (Input->keyboard.keys[SDL_SCANCODE_D].held) Player_Move(Vec2_Right), player.state.direction = Vec2_Add(Vec2_Right,player.state.direction);
    if (Input->keyboard.keys[SDL_SCANCODE_LSHIFT].pressed) player.state.movementLocked = true; //This just locks now :D
}