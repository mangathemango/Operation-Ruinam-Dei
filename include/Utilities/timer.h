#pragma once
#include <SDL.h>
#include <stdbool.h>

typedef struct {
    float startTime;
    float elapsedTime;
    float duration;
    bool inProgress;
    bool finished;
} Timer;

Timer* Timer_Create(float duration);
void Timer_Start(Timer *timer);
bool Timer_IsFinished(Timer *timer);
bool Timer_IsInProgress(Timer *timer);
void Timer_Destroy(Timer *timer);