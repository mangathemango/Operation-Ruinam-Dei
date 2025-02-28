#include <app.h>
#include <player.h>

/* 
*   This function is called every frame of the program AFTER App_Event_Handler().
*/
int App_PostUpdate() {
    SDL_RenderClear(app.setup.renderer);
    Player_PostUpdate();

    SDL_RenderPresent(app.setup.renderer);
    return 0;
}