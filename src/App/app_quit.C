#include <app.h>

/* Quit() is called once at the end of the program */
int App_Quit() {
    SDL_DestroyTexture(app.screenTexture);
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();
    return 0;
}