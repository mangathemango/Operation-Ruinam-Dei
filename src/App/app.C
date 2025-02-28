#include <app.h>

AppSetup setup = {
    .window = NULL,
    .renderer = NULL,
    .screenTexture = NULL,
};

AppState state = {
    .running = true,
};

AppConfig config = {
    .window_title = "Hello world" ,
    .window_width = 640 ,
    .window_height = 480 ,
    .window_fullscreen = false ,
    .screen_width = 160 ,
    .screen_height = 96 
};

AppData app = {
    .setup = setup,
    .state = state,
    .config = config
};