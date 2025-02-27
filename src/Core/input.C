#include <input.h>

static InputEvent _input;
const InputEvent * const Input = &_input;

void Press_Button(ButtonState *button) {
    button->pressed = true;
    button->held = true; 
}
void Release_Button(ButtonState *button) {
    button->released = true;
    button->held = false; 
}

void Reset_Button(ButtonState *button) {
    button->pressed = false;
    button->released = false;
}

void Input_PreUpdate() {
    Reset_Button(&_input.mouse.leftButton);
    Reset_Button(&_input.mouse.rightButton);
    Reset_Button(&_input.mouse.middleButton);
    for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
        Reset_Button(&_input.keyboard.keys[i]);
    }

    _input.mouse.scrollUp = false;
    _input.mouse.scrollDown = false;
    _input.mouse.motion = (Vec2) {0, 0};
    
    SDL_GetMouseState((int*) &_input.mouse.position.x, (int*) &_input.mouse.position.y);
}

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
        if (event->wheel.y > 0) {
            _input.mouse.scrollUp = true;
        } else if (event->wheel.y < 0) {
            _input.mouse.scrollDown = true;
        }
        break;
    case SDL_KEYDOWN:
        Press_Button(&_input.keyboard.keys[event->key.keysym.scancode]);
        break;
    case SDL_KEYUP:
        Release_Button(&_input.keyboard.keys[event->key.keysym.scancode]);
        break;
    }
}