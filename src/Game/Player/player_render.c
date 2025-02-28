#include <player.h>
#include <app.h>

int Player_Render() {
    SDL_FRect dstrect = {
        player.state.position.x - player.config.spriteSize.x / 2, 
        player.state.position.y - player.config.spriteSize.y / 2, 
        player.config.spriteSize.x, 
        player.config.spriteSize.y};
    SDL_RenderCopyF(app.setup.renderer, app.setup.screenTexture, NULL, &dstrect);
    SDL_RenderDrawRectF(app.setup.renderer, &dstrect);
    return 0;
}




