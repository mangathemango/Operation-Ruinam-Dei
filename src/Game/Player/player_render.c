#include <player.h>
#include <app.h>

int Player_Render() {
    SDL_FRect dstrect = { player.state.position.x, player.state.position.y, player.config.spriteSize.x, player.config.spriteSize.y };
    SDL_RenderCopyF(app.setup.renderer, app.setup.screenTexture, NULL, &dstrect);
    SDL_RenderDrawRectF(app.setup.renderer, &dstrect);
    SDL_RenderPresent(app.setup.renderer);
    return 0;
}




