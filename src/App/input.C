#include <input.h>

static InputEvent _input;
const InputEvent * const Input = &_input;


void Reset_Pressed_And_Released(ButtonState *button) {
    if (button->pressed) {
        button->pressed = false;
    }
    if (button->released) {
        button->released = false;
    }
}

void Reset_All_Button_Pressed_And_Released() {
    Reset_Pressed_And_Released(&_input.mouse.leftButton);
    Reset_Pressed_And_Released(&_input.mouse.rightButton);
    Reset_Pressed_And_Released(&_input.mouse.middleButton);
    for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
        Reset_Pressed_And_Released(&_input.keyboard.keys[i]);
    } 
}

void Update_Input(SDL_Event *event) {

    Reset_All_Button_Pressed_And_Released();

    SDL_GetMouseState((int*) &_input.mouse.position.x, (int*) &_input.mouse.position.y);

    switch (event->type) {
    case SDL_MOUSEMOTION:
        _input.mouse.position.x = event->motion.x;
        _input.mouse.position.y = event->motion.y;
        break;
    case SDL_MOUSEBUTTONDOWN:
        if (event->button.button == SDL_BUTTON_LEFT) {
            _input.mouse.leftButton.pressed = true;
            _input.mouse.leftButton.held = true;
        }
        if (event->button.button == SDL_BUTTON_RIGHT) {
            _input.mouse.rightButton.pressed = true;
            _input.mouse.rightButton.held = true;
        }
        if (event->button.button == SDL_BUTTON_MIDDLE) {
            _input.mouse.middleButton.pressed = true;
            _input.mouse.middleButton.held = true;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        if (event->button.button == SDL_BUTTON_LEFT) {
            _input.mouse.leftButton.released = true;
            _input.mouse.leftButton.held = false;
        }
        if (event->button.button == SDL_BUTTON_RIGHT) {
            _input.mouse.rightButton.released = true;
            _input.mouse.rightButton.held = false;
        }
        if (event->button.button == SDL_BUTTON_MIDDLE) {
            _input.mouse.middleButton.released = true;
            _input.mouse.middleButton.held = false;
        }
        break;
    case SDL_MOUSEWHEEL:
        if (event->wheel.y > 0) {
            _input.mouse.scrollUp = true;
        } else if (event->wheel.y < 0) {
            _input.mouse.scrollDown = true;
        } else {
            _input.mouse.scrollUp = false;
            _input.mouse.scrollDown = false;
        }
        break;
    case SDL_KEYDOWN:
        _input.keyboard.keys[event->key.keysym.scancode].pressed = true;
        _input.keyboard.keys[event->key.keysym.scancode].held = true;
        break;
    case SDL_KEYUP:
        _input.keyboard.keys[event->key.keysym.scancode].released = true;
        _input.keyboard.keys[event->key.keysym.scancode].held = false;
        break;
    }
}