#include <particle_emitterpresets.h>

ParticleEmitter Default_ParticleEmitter = {
    .position = {100, 100},

    .direction = {0, -1},
    .emissionRate = 0.02,
    .emissionNumber = 1,
    .maxParticles = 100,
    .angleRange = 60,

    .active = true,
    .emitterLifetime = 1,
    .emitterAge = 0,
    .loopCount = 5,
    .destroyWhenDone = true,

    .particleLifetime = 2,
    .particleSpeed = 200,
    .custom_Movement = NULL,

    .startColor = {255, 255, 100, 255},
    .endColor = {255, 255, 255, 0},
    .startSize = {5, 5},
    .endSize = {0, 0},
    .particleTexture = NULL,

    .gravity = {0, 0},
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
    emitter->particles = malloc(sizeof(Particle) * emitter->maxParticles);
    if (!emitter->particles) {
        free(emitter);
        return NULL;
    }
    return emitter;
}