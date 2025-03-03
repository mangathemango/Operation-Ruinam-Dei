#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL.h>
#include <stdbool.h>
#include <vec2.h>


typedef struct {
    Vec2 position;
    Vec2 size;
} AnimationFrame;

typedef struct {
    char* name;             // Animation name (e.g., "idle", "walk")
    AnimationFrame* frames; // Array of frames
    int frameCount;         // Number of frames
    float frameDuration;    // Time per frame in seconds
    bool looping;           // Whether animation should loop
} AnimationClip;

typedef struct {
    SDL_Texture* texture;   // Spritesheet texture
    AnimationClip* clips;   // Array of different animations
    int clipCount;          // Number of animation clips
    
    // Current animation state
    int currentClip;        // Currently active clip index
    int currentFrame;       // Current frame within the clip
    float timer;            // Time accumulator for frame changes
    bool isPlaying;         // Whether animation is playing
    int direction;          // 1 for forward, -1 for backward
} Animation;


// Create and destroy animations
Animation* Animation_Create(SDL_Texture* spritesheet);
void Animation_Destroy(Animation* animation);

// Add animation clips
void Animation_AddClip(Animation* animation, const char* name, 
                      AnimationFrame* frames, int frameCount, 
                      float frameDuration, bool looping);
AnimationFrame* Animation_GetFramesFromGrid(SDL_Texture *texture, Vec2 frameSize, int frameCount);
// Animation control
void Animation_Play(Animation* animation, const char* clipName);
void Animation_Stop(Animation* animation);
void Animation_Pause(Animation* animation);
void Animation_Resume(Animation* animation);

// Update and render
void Animation_Update(Animation* animation);
void Animation_Render(Animation* animation, Vec2 destPosition, Vec2 destSize);

#endif
