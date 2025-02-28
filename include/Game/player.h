#ifndef PLAYER_H
#define PLAYER_H
#include <vec2.h>

typedef struct {
    Vec2 position;
} PlayerState;

typedef struct {
    float speed;
    char* sprite;
    Vec2 spriteSize;
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

#endif