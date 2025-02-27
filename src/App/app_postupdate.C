#include <app.h>
#include <temp_renderer.h>

int App_PostUpdate() {
    Render_Texture();
    return 0;
}