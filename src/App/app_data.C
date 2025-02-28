#include <app.h>

AppData app = {
    .setup = {
        .window = NULL,
        .renderer = NULL,
        .screenTexture = NULL,
    },
    .state = {
        .running = true,
    },
    .config = {
        .window_title = "Hello world" ,
        .window_width = 640 ,
        .window_height = 480 ,
        .window_fullscreen = false ,
        .screen_width = 160 ,
        .screen_height = 96 
    }
};