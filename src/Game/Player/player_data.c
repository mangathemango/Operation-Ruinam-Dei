#include <player.h>

PlayerData player = {
    .state = {
        .position = {0,0},
    },
    .config = {
        .speed = 1,
        .sprite = "Assets/Images/idle.png",
        .spriteSize = {16,10},
    }
};