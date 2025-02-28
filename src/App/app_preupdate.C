#include <app.h>
#include <input.h>

/* 
*   This function is called every frame of the program BEFORE App_Event_Handler().
*/
int App_PreUpdate() {
    // Update delta time
    static Uint64 previousTicks = 0;
    Uint64 currentTicks = SDL_GetPerformanceCounter();
    app.time.deltaTime = (float)(currentTicks - previousTicks) / SDL_GetPerformanceFrequency();
    previousTicks = currentTicks;

    
    Input_PreUpdate();
    return 0;
}