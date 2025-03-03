#include <player.h>
#include <app.h>
/*
*   This function is called in App_Start().
?   It initializes the player's sprite texture. That's about it.
*/
int Player_Start() {
    // Load spin animation
    SDL_Texture* animationTexture = IMG_LoadTexture(app.setup.renderer, "Assets/Images/511212 sprite sheet.png");

    
    // Create animation object
    player.config.animation = Animation_Create(animationTexture);
    if (!player.config.animation) {
        SDL_Log("Failed to create animation");
        SDL_DestroyTexture(animationTexture);
        return 1;
    }

    AnimationFrame* idleFrames = Animation_GetFramesFromGrid(animationTexture, (Vec2) {481, 489}, 0, 0);
    if (!idleFrames) {
        SDL_Log("Failed to load idle frames");
        SDL_DestroyTexture(animationTexture);
        return 1;
    }
    Animation_AddClip(player.config.animation, "idle", idleFrames, 1, 0.04f, true);
    free(idleFrames); // Free after adding

    // Add spin animation
    AnimationFrame* spinFrames = Animation_GetFramesFromGrid(animationTexture, (Vec2) {481, 489}, 1, 29);
    if (!spinFrames) {
        SDL_Log("Failed to load spin frames: %s", SDL_GetError());
        SDL_DestroyTexture(animationTexture);
        return 1;
    }
    Animation_AddClip(player.config.animation, "spin", spinFrames, 27, 0.04f, true);
    free(spinFrames); // Free after adding

    Animation_Play(player.config.animation, "idle");
    return 0;
}