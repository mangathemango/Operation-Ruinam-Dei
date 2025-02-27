#include <app.h>
#include <input.h>

/* Handle_Event() is called every time an event is detected (keyboard, mouse, etc.) */
int App_Event_Handler(SDL_Event *event) {
    if (event->type == SDL_QUIT) {
        app.running = 0;
    }
    Input_Event_Handler(event);
    return 0;
}