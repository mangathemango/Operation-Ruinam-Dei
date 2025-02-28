#include <app.h>

/* 
*   This function is called when the program is about to quit.
*/
int App_Quit() {
    SDL_DestroyTexture(app.screenTexture);
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();
    return 0;
}