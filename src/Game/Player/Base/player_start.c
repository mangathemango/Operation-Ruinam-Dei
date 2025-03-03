#include <player.h>
#include <app.h>
/*
*   This function is called in App_Start().
?   It initializes the player's sprite texture. That's about it.
*/
int Player_Start() {
    // Load spin animation
    SDL_Texture* spinAnimationTexture = IMG_LoadTexture(app.setup.renderer, "Assets/Images/spinning-spritesheet.png");
    if (!spinAnimationTexture) {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        return 1;
    }
    
    // Create animation object
    player.config.animation = Animation_Create(spinAnimationTexture);
    if (!player.config.animation) {
        SDL_Log("Failed to create animation");
        SDL_DestroyTexture(spinAnimationTexture);
        return 1;
    }
    
    // Add spin animation
    AnimationFrame* spinFrames = Animation_GetFramesFromGrid(spinAnimationTexture, (Vec2) {481, 489}, 30);
    if (!spinFrames) {
        SDL_Log("Failed to load spin frames: %s", SDL_GetError());
        return 1;
    }
    Animation_AddClip(player.config.animation, "spin", spinFrames, 30, 0.04f, true);
    free(spinFrames); // Free after adding
    
    // Add idle animation
    SDL_Texture* idleAnimationTexture = IMG_LoadTexture(app.setup.renderer, "Assets/Images/idle-spritesheet.png");
    if (!idleAnimationTexture) {
        SDL_Log("Failed to load idle image: %s", SDL_GetError());
        return 1;
    }
    AnimationFrame* idleFrames = Animation_GetFramesFromGrid(idleAnimationTexture, (Vec2) {481, 489}, 1);
    if (!idleFrames) {
        SDL_Log("Failed to load idle frames");
        SDL_DestroyTexture(idleAnimationTexture);
        return 1;
    }
    Animation_AddClip(player.config.animation, "idle", idleFrames, 1, 0.04f, true);
    free(idleFrames); // Free after adding

    Animation_Play(player.config.animation, "idle");
    return 0;
}