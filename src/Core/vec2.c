#include <vec2.h>
#include <math.h>

float Vec2_Magnitude(Vec2 v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

Vec2 Vec2_Normalize(Vec2 v) {
    float mag = Vec2_Magnitude(v);
    return (Vec2) {v.x / mag, v.y / mag};
}

Vec2 Vec2_Add(Vec2 a, Vec2 b) {
    return (Vec2) {a.x + b.x, a.y + b.y};
}

Vec2 Vec2_Subtract(Vec2 a, Vec2 b) {
    return (Vec2) {a.x - b.x, a.y - b.y};
}

Vec2 Vec2_Multiply(Vec2 v, float scalar) {
    return (Vec2) {v.x * scalar, v.y * scalar};
}

Vec2 Vec2_Divide(Vec2 v, float scalar) {
    return (Vec2) {v.x / scalar, v.y / scalar};
}

float Vec2_Dot(Vec2 a, Vec2 b) {
    return a.x * b.x + a.y * b.y;
}

Vec2 Vec2_Lerp(Vec2 a, Vec2 b, float t) {
    return (Vec2) {a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t};
}

