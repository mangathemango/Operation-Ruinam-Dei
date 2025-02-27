#include <app.h>
#include <temp_renderer.h>

/* 
    This function is called every frame of the program AFTER App_Event_Handler().
*/
int App_PostUpdate() {
    Render_Texture();
    return 0;
}