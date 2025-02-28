#include <temp_renderer.h>
#include <app.h>

/*
!   This is a temporary renderer for 5112 image. It will be replaced with a more robust renderer in the future.
*/

/* Prepares the screen texture */
int Prepare_Screen_Texture() {
    // Free previous texture if it exists
    if (app.setup.screenTexture) {
        SDL_DestroyTexture(app.setup.screenTexture);
        app.setup.screenTexture = NULL;
    }
    
    app.setup.screenTexture = IMG_LoadTexture(app.setup.renderer, "Assets/Images/idle.png");
    
    if (!app.setup.screenTexture) {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        return 1;
    }
    return 0;
}

/* Render the current texture */
int Render_Texture() {
    SDL_RenderClear(app.setup.renderer);
    SDL_FRect dstrect = { 0, 0, 160, 96 };
    SDL_RenderCopyF(app.setup.renderer, app.setup.screenTexture, NULL, &dstrect);
    SDL_RenderDrawRectF(app.setup.renderer, &dstrect);
    SDL_RenderPresent(app.setup.renderer);
    return 0;
}
