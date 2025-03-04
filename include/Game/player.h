/*
    @file player.h
*   This file contains the player's data, actions, and functions.
    TODO: Add player stats and abilities struct as well.
*/

#ifndef PLAYER_H
#define PLAYER_H
#include <vec2.h>
#include <animation.h>
#include <stdbool.h>

typedef struct {
    Vec2 position;
    Vec2 direction; //This is added to know the players last direction
    bool movementLocked; //to know if the movement is locked
    bool moving;    
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
int Player_Preupdate();

// Actions
int Player_Move(Vec2 direction);
int Player_Dash(Vec2 direction);
void Player_WrapAroundScreen(); //! This is temporary and will be removed later.
void ResetDirection();
int dashing();
int dashCooldown();

// Animations
int Player_AnimationInit();
#endif