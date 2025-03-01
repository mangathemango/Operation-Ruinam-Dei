#include <time_manager.h>

TimeManager time = {
    .timeDeltaSeconds = 0,
    .timeScale = 1,
    .scaledTimeDeltaSeconds = 0,
    .totalTimeSeconds = 0
};

extern const TimeManager * const Time = &time;

void TimeManager_Update() {
    time.timeDeltaSeconds = (float)SDL_GetTicks() / 1000.0f;
    time.scaledTimeDeltaSeconds = time.timeDeltaSeconds * time.timeScale;
    time.totalTimeSeconds += time.scaledTimeDeltaSeconds;
}