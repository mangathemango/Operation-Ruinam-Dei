#include <particle_emitterpresets.h>

ParticleEmitter Default_ParticleEmitter = {
    .position = {100, 100},

    .direction = {0, -1},
    .emissionRate = 0.1,
    .emissionNumber = 10,
    .maxParticles = 100,
    .angleRange = 360,

    .active = true,
    .emitterLifetime = 0,
    .emitterAge = 0,
    .loopCount = -1,

    .particleLifetime = 1,
    .particleSpeed = 200,
    .custom_Movement = Particle_DeceleratedMovement,

    .startColor = {255, 255, 255, 255},
    .endColor = {255, 255, 255, 0},
    .particleSize = {1, 1},
    .particleTexture = NULL,

    .gravity = {0, 0},
    .drag = 0.3,

    .particles = NULL,
    .readyIndex = 0,

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