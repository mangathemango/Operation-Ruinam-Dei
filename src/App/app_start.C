#include <app.h>
#include <initialize_SDL.h>
#include <temp_renderer.h>

/*
    This function is called at the start of the program.
    It initializes everything needed for the program to run. Like the window, renderer, and later, the game.
*/
int App_Start() {
    if (Initialize_SDL()) return 1;
    Prepare_Screen_Texture();
    return 0;
}