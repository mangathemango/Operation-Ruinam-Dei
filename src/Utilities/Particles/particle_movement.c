#include <particle_movement.h>
#include <time_system.h>

void Particle_LinearMovement(Particle* particle) {
    Vec2 velocity = {
        particle->direction.x * particle->speed,
        particle->direction.y * particle->speed
    };
    particle->position.x += velocity.x * Time->deltaTimeSeconds;
    particle->position.y += velocity.y * Time->deltaTimeSeconds;
}

void Particle_AcceleratedMovement(Particle* particle) {
    particle->speed += 100 * Time->deltaTimeSeconds;
    Vec2 velocity = {
        particle->direction.x * particle->speed,
        particle->direction.y * particle->speed
    };
    particle->position.x += velocity.x * Time->deltaTimeSeconds;
    particle->position.y += velocity.y * Time->deltaTimeSeconds;
}

void Particle_DeceleratedMovement(Particle* particle) {
    particle->speed -= Time->deltaTimeSeconds * particle->speed * 2.7;
    Vec2 velocity = {
        particle->direction.x * particle->speed,
        particle->direction.y * particle->speed
    };
    particle->position.x += velocity.x * Time->deltaTimeSeconds;
    particle->position.y += velocity.y * Time->deltaTimeSeconds;
}

void Particle_SpiralMovement(Particle* particle) {
    Vec2 velocity = {
        particle->direction.x * particle->speed,
        particle->direction.y * particle->speed
    };
    particle->position.x += velocity.x * Time->deltaTimeSeconds;
    particle->position.y += velocity.y * Time->deltaTimeSeconds;

}

void Particle_RandomMovement(Particle* particle) {
    Vec2 velocity = {
        particle->direction.x * particle->speed,
        particle->direction.y * particle->speed
    };
    particle->position.x += velocity.x * Time->deltaTimeSeconds;
    particle->position.y += velocity.y * Time->deltaTimeSeconds;
    particle->position.x += (rand() % 3 - 1);
    particle->position.y += (rand() % 3 - 1);
}