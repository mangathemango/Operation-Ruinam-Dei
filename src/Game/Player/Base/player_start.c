#include <player.h>
#include <app.h>
/*
*   This function is called in App_Start().
?   It initializes the player's sprite texture. That's about it.
*/
int Player_Start() {
    SDL_Texture* animationTexture = IMG_LoadTexture(app.setup.renderer, "Assets/Images/spinning-spritesheet.png");
    if (!animationTexture) {
        SDL_Log("Failed to load image: %s", SDL_GetError());
    }
    AnimationFrame* frame = Animation_GetFramesFromGrid(animationTexture, (Vec2) {481, 489}, 30);
    if (!frame) {
        SDL_Log("Failed to load frames: %s", SDL_GetError());
    }
    Animation* animation = Animation_Create(animationTexture);
    Animation_AddClip(animation, "spin", frame, 30, 0.04f, true);
    player.config.animation = animation;

    Animation_Play(player.config.animation, "spin");
    return 0;
}