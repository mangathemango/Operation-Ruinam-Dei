#include <time_system.h>

TimeSystem time = {
    .deltaTimeSeconds = 0,
    .timeScale = 1,
    .scaledDeltaTimeSeconds = 0,
    .totalTimeSeconds = 0
};

extern const TimeSystem * const Time = &time;

void Time_Update() {
    time.deltaTimeSeconds = (float)SDL_GetTicks() / 1000.0f;
    time.scaledDeltaTimeSeconds = time.deltaTimeSeconds * time.timeScale;
    time.totalTimeSeconds += time.deltaTimeSeconds;
}

void Time_SetTimeScale(float scale) {
    time.timeScale = scale;
}

void Time_ResetTotalTime() {
    time.totalTimeSeconds = 0;
}