#include <player.h>
#include <app.h>

PlayerData player = {
    .state = {
        .position = {0,0},
    },
    .config = {
        .speed = 1,
        .sprite = "Assets/Images/idle.png",
        .spriteSize = {16, 16},
    }
};

int Player_Render() {
    SDL_Texture* texture = IMG_LoadTexture(app.setup.renderer, player.config.sprite);
    if (!texture) {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        return 1;
    }
    SDL_FRect dstrect = { player.state.position.x, player.state.position.y, player.config.spriteSize.x, player.config.spriteSize.y };
    SDL_RenderCopyF(app.setup.renderer, texture, NULL, &dstrect);
    SDL_RenderDrawRectF(app.setup.renderer, &dstrect);
    SDL_DestroyTexture(texture);
    return 0;
}

