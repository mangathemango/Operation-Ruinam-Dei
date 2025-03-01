#pragma once
#include <SDL.h>

typedef struct {
    float timeDeltaSeconds;
    float timeScale;
    float scaledTimeDeltaSeconds;
    double totalTimeSeconds;
} TimeManager;

extern const TimeManager * const Time;

void TimeManager_Update();
void TimeManager_SetTimeScale(float scale);
void TimeManager_ResetTotalTime();
