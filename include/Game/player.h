/*
    @file player.h
*   This file contains the player's data, actions, and functions.
    TODO: Add player stats and abilities struct as well.
*/

#ifndef PLAYER_H
#define PLAYER_H
#include <vec2.h>
#include <animation.h>

typedef struct {
    Vec2 position;
} PlayerState;

typedef struct {
    float speed;
    char* sprite;
    Vec2 spriteSize;
    Animation* animation;
} PlayerConfig;

typedef struct {
    PlayerState state;
    PlayerConfig config;
} PlayerData;

extern PlayerData player;


void Player_Input_Handler();
int Player_Render();

int Player_Start();
int Player_PostUpdate();

// Actions
int Player_Move(Vec2 direction);
int Player_Dash(Vec2 direction);
void Player_WrapAroundScreen(); //! This is temporary and will be removed later.

#endif