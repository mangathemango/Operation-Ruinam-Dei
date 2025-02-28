#include <player.h>
#include <app.h>
#include <input.h>

PlayerData player = {
    .state = {
        .position = {0,0},
    },
    .config = {
        .speed = 1,
        .sprite = "Assets/Images/idle.png",
        .spriteSize = {16,10},
    }
};

int Player_Start() {
    app.setup.screenTexture = IMG_LoadTexture(app.setup.renderer, player.config.sprite);
    if (!app.setup.screenTexture) {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        return 1;
    }
    return 0;
}
int Player_Render() {
    SDL_RenderClear(app.setup.renderer);
    SDL_FRect dstrect = { player.state.position.x, player.state.position.y, player.config.spriteSize.x, player.config.spriteSize.y };
    SDL_RenderCopyF(app.setup.renderer, app.setup.screenTexture, NULL, &dstrect);
    SDL_RenderDrawRectF(app.setup.renderer, &dstrect);
    SDL_RenderPresent(app.setup.renderer);
    return 0;
}

int Player_Move(Vec2 direction) {
    player.state.position.x += direction.x * player.config.speed;
    player.state.position.y += direction.y * player.config.speed;
    return 0;
}

int Player_Update() {
    if (Input->keyboard.keys[SDL_SCANCODE_W].held) Player_Move(Vec2_Up);
    if (Input->keyboard.keys[SDL_SCANCODE_A].held) Player_Move(Vec2_Left);
    if (Input->keyboard.keys[SDL_SCANCODE_S].held) Player_Move(Vec2_Down);
    if (Input->keyboard.keys[SDL_SCANCODE_D].held) Player_Move(Vec2_Right);
    return 0;
}


