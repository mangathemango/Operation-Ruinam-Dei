#include <app.h>
#include <input.h>

/* 
    This function is called every frame of the program BEFORE App_Event_Handler().
*/
int App_PreUpdate() {
    Input_PreUpdate();
    return 0;
}