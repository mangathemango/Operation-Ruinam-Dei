#include <player.h>
#include <app.h>
/*
*   This function is called in App_Start().
?   It initializes the player's sprite texture. That's about it.
*/
int Player_Start() {
    app.setup.screenTexture = IMG_LoadTexture(app.setup.renderer, player.config.sprite);
    if (!app.setup.screenTexture) {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        return 1;
    }
    return 0;
}