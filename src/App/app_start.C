#include <app.h>
#include <temp_renderer.h>

/*
    This function is called at the start of the program.
    It initializes everything needed for the program to run. Like the window, renderer, and later, the game.
*/
int App_Start() {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    // Set up window
    app.window = SDL_CreateWindow(WINDOW_TITLE,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_FULLSCREEN ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
    
    if (!app.window) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return 1;
    }

    SDL_SetWindowPosition(app.window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_RaiseWindow(app.window);


    // Set up renderer
    app.renderer = SDL_CreateRenderer(app.window, -1,
        SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
    
    if (!app.renderer) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return 1;
    }

    SDL_RenderSetLogicalSize(app.renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    Prepare_Screen_Texture();
    return 0;
}