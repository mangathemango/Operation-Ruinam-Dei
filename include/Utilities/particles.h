#include <SDL.h>
#include <vec2.h>
#include <stdbool.h>

typedef struct {
    Vec2 position;
    Vec2 direction;
    float speed;
    bool alive;
    float maxLifeTime;
    float timeAlive;
} Particle;


typedef struct {
    Vec2 position;                          // Position of the emitter
    Vec2 direction;                         // Direction of the particles
    float angleRange;                       // Angle range in degrees
    float particleLifetime;                 // How long the particles live in seconds
    float particleSpeed;                 // How fast the particles move in pixels per second
    float emissionRate;                     // Time between emissions in seconds
    int emissionNumber;                     // Number of particles to emit per emission
    int maxParticles;                       // Number of particles this emitter can emit at once
    Particle* particles;                    // Array of particles
    int readyIndex;                         // Index of the next particle to emit
    void (*custom_Movement)(Particle*);     // Custom movement function
} ParticleEmitter;

extern ParticleEmitter Default_ParticleEmitter;
extern ParticleEmitter* test_emitter;

void Particle_LinearMovement(Particle* particle);
void Particle_AcceleratedMovement(Particle* particle);
void Particle_DeceleratedMovement(Particle* particle);
void Particle_SpiralMovement(Particle* particle);
void Particle_RandomMovement(Particle* particle);

ParticleEmitter* ParticleEmitter_CreateDefault();
void ParticleEmitter_SetMaxParticles(ParticleEmitter* emitter, int maxParticles);
void ParticleEmitter_Emit(ParticleEmitter* emitter);
int ParticleEmitter_GetNextReady(ParticleEmitter* emitter);
void ParticleEmitter_UpdateParticles(ParticleEmitter* emitter);
void ParticleEmitter_Update(ParticleEmitter* emitter);
void ParticleEmitter_Render(ParticleEmitter* emitter);
void ParticleEmitter_DestroyEmitter(ParticleEmitter* emitter);