#include <input.h>

static InputEvent _input;
const InputEvent * const Input = &_input; // This ensures that the Input variable is read-only to other files.

/*
*   Presses a button.
?   @param button The button to press. Can either be a key button or a mouse button.
*/
void Press_Button(ButtonState *button) {
    button->pressed = true;
    button->held = true; 
}

/*
*   Releases a button.
?   @param button The button to release. Can either be a key button or a mouse button.
*/
void Release_Button(ButtonState *button) {
    button->released = true;
    button->held = false; 
}

/*
*   Resets a button's pressed and released states.
?   This function is called every frame to ensure that the button's pressed and released states are only true for one frame.
?   @param button The button to release. Can either be a key button or a mouse button.
*/
void Reset_Button(ButtonState *button) {
    button->pressed = false;
    button->released = false;
}


/*
*   This function is called inside App_PreUpdate().
?   It resets all the buttons and mouse motion.
*/
void Input_PreUpdate() {
    // Reset all the buttons
    Reset_Button(&_input.mouse.leftButton);
    Reset_Button(&_input.mouse.rightButton);
    Reset_Button(&_input.mouse.middleButton);
    for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
        Reset_Button(&_input.keyboard.keys[i]);
    }

    // Reset the mouse scroll
    _input.mouse.scrollUp = false;
    _input.mouse.scrollDown = false;

    // Reset the mouse motion
    _input.mouse.motion = (Vec2) {0, 0};
    
    // Get the mouse position
    SDL_GetMouseState((int*) &_input.mouse.position.x, (int*) &_input.mouse.position.y);
}


/*
*   This function is called inside App_Event_Handler().
?   It updates the InputEvent struct based on the SDL_Event.
    @param event The SDL_Event to update the InputEvent struct with.
*/
void Input_Event_Handler(SDL_Event *event) {
    switch (event->type) {
    case SDL_MOUSEMOTION:
        _input.mouse.position.x = event->motion.x;
        _input.mouse.position.y = event->motion.y;
        break;
    case SDL_MOUSEBUTTONDOWN:
        if (event->button.button == SDL_BUTTON_LEFT)   Press_Button(&_input.mouse.leftButton);
        if (event->button.button == SDL_BUTTON_RIGHT)  Press_Button(&_input.mouse.rightButton);
        if (event->button.button == SDL_BUTTON_MIDDLE) Press_Button(&_input.mouse.middleButton);
        break;
    case SDL_MOUSEBUTTONUP:
        if (event->button.button == SDL_BUTTON_LEFT)   Release_Button(&_input.mouse.leftButton);
        if (event->button.button == SDL_BUTTON_RIGHT)  Release_Button(&_input.mouse.rightButton);
        if (event->button.button == SDL_BUTTON_MIDDLE) Release_Button(&_input.mouse.middleButton);
        break;
    case SDL_MOUSEWHEEL:
        if (event->wheel.y > 0) _input.mouse.scrollUp = true;
        if (event->wheel.y < 0) _input.mouse.scrollDown = true;
        break;
    case SDL_KEYDOWN:
        Press_Button(&_input.keyboard.keys[event->key.keysym.scancode]);
        break;
    case SDL_KEYUP:
        Release_Button(&_input.keyboard.keys[event->key.keysym.scancode]);
        break;
    }
}