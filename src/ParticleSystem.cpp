#include "ParticleSystem.h"
#include <cstdlib>
#include <ctime>

ParticleSystem::ParticleSystem(int maxParticles)
    : maxParticles(maxParticles), nextParticleIndex(0) {
    particles.resize(maxParticles);
    std::srand(std::time(nullptr));
}

void ParticleSystem::emit(const Vector3& position, const Vector3& direction, int count) {
    for (int i = 0; i < count && i < maxParticles; i++) {
        Particle& p = particles[nextParticleIndex];
        
        p.position = position;
        
        // Random velocity based on direction
        float spreadX = ((std::rand() % 200 - 100) / 100.0f) * 2.0f;
        float spreadY = ((std::rand() % 200 - 100) / 100.0f) * 2.0f;
        float spreadZ = ((std::rand() % 200 - 100) / 100.0f) * 2.0f;
        
        p.velocity = (direction + Vector3(spreadX, spreadY, spreadZ)) * 5.0f;
        
        // Random color (orange/yellow for muzzle flash)
        p.color = Vector3(
            1.0f,
            0.5f + (std::rand() % 50) / 100.0f,
            0.1f + (std::rand() % 30) / 100.0f
        );
        
        p.lifetime = 0.3f + (std::rand() % 50) / 100.0f;
        p.maxLifetime = p.lifetime;
        p.size = 0.05f + (std::rand() % 30) / 1000.0f;
        
        nextParticleIndex = (nextParticleIndex + 1) % maxParticles;
    }
}

void ParticleSystem::update(float deltaTime) {
    for (auto& p : particles) {
        if (p.isAlive()) {
            p.lifetime -= deltaTime;
            p.position += p.velocity * deltaTime;
            p.velocity.y -= 5.0f * deltaTime; // Gravity
        }
    }
}
