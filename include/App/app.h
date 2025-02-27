#ifndef APP_H
#define APP_H

#include <SDL.h>
#include <SDL_image.h>

#define WINDOW_TITLE "Hello World!"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define WINDOW_FULLSCREEN 0
#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 96

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* screenTexture;
    int running;
} AppData;

extern AppData app;

int App_Start();
int App_PreUpdate();
int App_PostUpdate();
int App_Event_Handler(SDL_Event *event);
int App_Quit();

#endif