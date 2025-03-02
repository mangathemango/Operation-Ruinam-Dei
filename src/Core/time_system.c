#include <time_system.h>

TimeSystem time = {
    .deltaTimeSeconds = 0,
    .timeScale = 1,
    .scaledDeltaTimeSeconds = 0,
    .programElapsedTimeSeconds = 0,
    .previousTick = 0
};

const TimeSystem * const Time = &time;


void Time_PreUpdate() {
    float currentTick = SDL_GetTicks();
    time.deltaTimeSeconds = (currentTick - time.previousTick) / 1000;
    time.previousTick = currentTick;
    time.scaledDeltaTimeSeconds = time.deltaTimeSeconds * time.timeScale;
    time.programElapsedTimeSeconds += time.deltaTimeSeconds;

}

void Time_SetTimeScale(float scale) {
    time.timeScale = scale;
}

void Time_ResetTotalTime() {
    time.programElapsedTimeSeconds = 0;
}