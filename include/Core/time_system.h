#pragma once
#include <SDL.h>

typedef struct {
    float deltaTimeSeconds;
    float timeScale;
    float scaledDeltaTimeSeconds;
    double programElapsedTimeSeconds;
    double previousTick;
} TimeSystem;

extern const TimeSystem * const Time;

void Time_PreUpdate();
void Time_SetTimeScale(float scale);
void Time_ResetTotalTime();
