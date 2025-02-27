#include <temp_renderer.h>
#include <app.h>

/*
!   This is a temporary renderer for 5112 image. It will be replaced with a more robust renderer in the future.
*/

/* Prepares the screen texture */
int Prepare_Screen_Texture() {
    // Free previous texture if it exists
    if (app.screenTexture) {
        SDL_DestroyTexture(app.screenTexture);
        app.screenTexture = NULL;
    }
    
    app.screenTexture = IMG_LoadTexture(app.renderer, "Assets/Images/idle.png");
    
    if (!app.screenTexture) {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        return 1;
    }
    return 0;
}

/* Render the current texture */
int Render_Texture() {
    SDL_RenderClear(app.renderer);
    SDL_FRect dstrect = { 0, 0, 160, 96 };
    SDL_RenderCopyF(app.renderer, app.screenTexture, NULL, &dstrect);
    SDL_RenderDrawRectF(app.renderer, &dstrect);
    SDL_RenderPresent(app.renderer);
    return 0;
}
