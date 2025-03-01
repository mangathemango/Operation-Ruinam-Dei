#pragma once
#include <SDL.h>

typedef struct {
    float deltaTimeSeconds;
    float timeScale;
    float scaledDeltaTimeSeconds;
    double totalTimeSeconds;
} TimeSystem;

extern const TimeSystem * const Time;

void Time_Update();
void Time_SetTimeScale(float scale);
void Time_ResetTotalTime();
