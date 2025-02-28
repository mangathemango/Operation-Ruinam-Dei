#include <app.h>
#include <player.h>

/* 
*   This function is called every frame of the program AFTER App_Event_Handler().
*/
int App_PostUpdate() {
    Player_Update();
    Player_Render();
    return 0;
}