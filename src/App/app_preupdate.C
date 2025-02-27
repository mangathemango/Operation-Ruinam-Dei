#include <app.h>
#include <input.h>

/* Update() is called every frame of the program */
int App_PreUpdate() {
    Update_Input();
    return 0;
}