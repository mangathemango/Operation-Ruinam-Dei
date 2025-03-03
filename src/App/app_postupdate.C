#include <app.h>
#include <player.h>
#include <particles.h>

/* 
*   This function is called every frame of the program AFTER App_Event_Handler().
?   This is suitable for rendering and updating the game.
*/
int App_PostUpdate() {
    SDL_RenderClear(app.setup.renderer); // Clear previous renderer

    Player_PostUpdate();
    ParticleEmitter_Update(test_emitter);
    SDL_RenderPresent(app.setup.renderer);  // Present the renderer
    return 0;
}