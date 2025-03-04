#include <particle_emitterpresets.h>

ParticleEmitter Default_ParticleEmitter = {
    .position = {100, 100},

    .direction = {0, -1},
    .emissionRate = 0.1,
    .emissionNumber = 3,
    .maxParticles = 100,
    .angleRange = 360,

    .active = true,
    .emitterLifetime = 0,
    .emitterAge = 0,
    .loopCount = 1,
    .destroyWhenDone = true,

    .particleLifetime = 2,
    .particleSpeed = 150,
    .custom_Movement = NULL,

    .startColor = {255, 255, 100, 255},
    .endColor = {255, 255, 255, 0},
    .startSize = {5, 5},
    .endSize = {0, 0},
    .particleTexture = NULL,

    .gravity = {0, 30},
    .drag = 2.7,

    .particles = NULL,
    .readyIndex = 0,
    .selfReference = NULL,
};

ParticleEmitter* test_emitter = NULL;

ParticleEmitter* ParticleEmitter_CreateDefault() {
    ParticleEmitter* emitter = malloc(sizeof(ParticleEmitter));
    if (!emitter) return NULL;
    memcpy(emitter, &Default_ParticleEmitter, sizeof(ParticleEmitter));
    emitter->emissionTimer = Timer_Create(emitter->emissionRate);
    Timer_Start(emitter->emissionTimer);
    emitter->particles = malloc(sizeof(Particle) * emitter->maxParticles);
    if (!emitter->particles) {
        free(emitter);
        return NULL;
    }
    return emitter;
}