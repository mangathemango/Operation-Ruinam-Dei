#include <particles.h>
#include <app.h>
#include <time_system.h>
#include <timer.h>
#include <random.h>

void ParticleEmitter_SetMaxParticles(ParticleEmitter* emitter, int maxParticles) {
    emitter->maxParticles = maxParticles;
    emitter->particles = realloc(emitter->particles, sizeof(Particle) * emitter->maxParticles);
}

void ParticleEmitter_Emit(ParticleEmitter* emitter) {
    if (emitter->readyIndex == emitter->maxParticles) return;
    emitter->particles[emitter->readyIndex].position = emitter->position;
    emitter->particles[emitter->readyIndex].direction = Vec2_RotateDegrees(emitter->direction, RandFloat(-emitter->angleRange / 2, emitter->angleRange / 2));
    emitter->particles[emitter->readyIndex].speed = emitter->particleSpeed;
    emitter->particles[emitter->readyIndex].alive = true;
    emitter->particles[emitter->readyIndex].maxLifeTime = emitter->particleLifetime;
    emitter->particles[emitter->readyIndex].timeAlive = 0;
    emitter->readyIndex = ParticleEmitter_GetNextReady(emitter);
}

int ParticleEmitter_GetNextReady(ParticleEmitter* emitter) {
    for (int i = 0; i < emitter->maxParticles; i++) {
        if (!emitter->particles[i].alive) return i;
    }
    return emitter->maxParticles;
}

void ParticleEmitter_UpdateParticles(ParticleEmitter* emitter) {
    for (int i = 0; i < emitter->maxParticles; i++) {
        if (!emitter->particles[i].alive) {
            continue;
        }
        emitter->particles[i].timeAlive += Time->deltaTimeSeconds;
        if (emitter->particles[i].timeAlive >= emitter->particles[i].maxLifeTime) {
            emitter->particles[i].alive = false;
            emitter->readyIndex = i;
        }
        if (emitter->custom_Movement) {
            emitter->custom_Movement(&emitter->particles[i]);
        } else {
            emitter->particles[i].position.x += emitter->particles[i].direction.x * emitter->particles[i].speed * Time->deltaTimeSeconds;
            emitter->particles[i].position.y += emitter->particles[i].direction.y * emitter->particles[i].speed * Time->deltaTimeSeconds;
        }
    }
}

void ParticleEmitter_Update(ParticleEmitter* emitter) {
    static Timer* emissionTimer = NULL;
    if (emissionTimer == NULL) {
        emissionTimer = Timer_Create(emitter->emissionRate);
        Timer_Start(emissionTimer);
    }
    if (Timer_IsFinished(emissionTimer)) {
        for (int i = 0; i < emitter->emissionNumber; i++) {
            ParticleEmitter_Emit(emitter);
        }
        Timer_Start(emissionTimer);
    }
    ParticleEmitter_UpdateParticles(emitter);
    ParticleEmitter_Render(emitter);    
}

void ParticleEmitter_Render(ParticleEmitter* emitter) {
    for (int i = 0; i < emitter->maxParticles; i++) {
        if (!emitter->particles[i].alive) {
            continue;
        }
        SDL_Rect rect = {
            emitter->particles[i].position.x,
            emitter->particles[i].position.y,
            1,
            1
        };
        SDL_SetRenderDrawColor(app.setup.renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(app.setup.renderer, &rect);
    }
}