#include <app.h>

/* 
*   This function is called when the program is about to quit.
*/
int App_Quit() {
    SDL_DestroyTexture(app.setup.screenTexture);
    SDL_DestroyRenderer(app.setup.renderer);
    SDL_DestroyWindow(app.setup.window);
    SDL_Quit();
    return 0;
}