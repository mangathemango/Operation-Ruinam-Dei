#ifndef VEC2_H
#define VEC2_H
typedef struct 
{
    float x;
    float y;
} Vec2;

static const Vec2 Vec2_Zero = {0, 0};
static const Vec2 Vec2_Up = {0, -1};
static const Vec2 Vec2_Down = {0, 1};
static const Vec2 Vec2_Left = {-1, 0};
static const Vec2 Vec2_Right = {1, 0};

#endif