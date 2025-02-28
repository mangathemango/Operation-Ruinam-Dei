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

int Player_Render();