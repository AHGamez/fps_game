#include "ParticleSystem.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

ParticleSystem::ParticleSystem(int maxParticles)
    : maxParticles(maxParticles), nextParticleIndex(0) {
    particles.resize(maxParticles);
    std::srand(std::time(nullptr));
}

void ParticleSystem::emit(const Vector3& position, const Vector3& direction, int count) {
    emitTyped(position, direction, count, ParticleType::MUZZLE_FLASH);
}

void ParticleSystem::emitTyped(const Vector3& position, const Vector3& direction, int count, ParticleType type) {
    for (int i = 0; i < count && i < maxParticles; i++) {
        // Random velocity based on direction
        float spreadX = ((std::rand() % 200 - 100) / 100.0f) * 2.0f;
        float spreadY = ((std::rand() % 200 - 100) / 100.0f) * 2.0f;
        float spreadZ = ((std::rand() % 200 - 100) / 100.0f) * 2.0f;
        
        Vector3 velocity = (direction + Vector3(spreadX, spreadY, spreadZ)) * 5.0f;
        Vector3 color;
        float lifetime;
        float size;
        
        switch (type) {
            case ParticleType::MUZZLE_FLASH:
                color = Vector3(1.0f, 0.5f + (std::rand() % 50) / 100.0f, 0.1f + (std::rand() % 30) / 100.0f);
                lifetime = 0.3f + (std::rand() % 50) / 100.0f;
                size = 0.05f + (std::rand() % 30) / 1000.0f;
                break;
                
            case ParticleType::SPARK:
                color = Vector3(1.0f, 0.9f, 0.3f);
                lifetime = 0.5f + (std::rand() % 50) / 100.0f;
                size = 0.03f + (std::rand() % 20) / 1000.0f;
                velocity = velocity * 0.8f;
                break;
                
            case ParticleType::SMOKE:
                color = Vector3(0.5f, 0.5f, 0.5f);
                lifetime = 1.5f + (std::rand() % 100) / 100.0f;
                size = 0.1f + (std::rand() % 50) / 1000.0f;
                velocity = velocity * 0.3f;
                velocity.y += 2.0f; // Smoke rises
                break;
                
            case ParticleType::EXPLOSION:
                color = Vector3(1.0f, 0.3f + (std::rand() % 40) / 100.0f, 0.0f);
                lifetime = 0.8f + (std::rand() % 60) / 100.0f;
                size = 0.08f + (std::rand() % 40) / 1000.0f;
                velocity = velocity * 1.5f;
                break;
        }
        
        emitParticle(position, velocity, color, lifetime, size, type);
    }
}

void ParticleSystem::emitExplosion(const Vector3& position, int count) {
    for (int i = 0; i < count && i < maxParticles; i++) {
        // Spherical distribution
        float theta = ((std::rand() % 360) / 360.0f) * 2.0f * 3.14159265f;
        float phi = ((std::rand() % 180) / 180.0f) * 3.14159265f;
        
        float x = std::sin(phi) * std::cos(theta);
        float y = std::sin(phi) * std::sin(theta);
        float z = std::cos(phi);
        
        Vector3 velocity(x, y, z);
        velocity = velocity * (5.0f + (std::rand() % 50) / 10.0f);
        
        Vector3 color(1.0f, 0.3f + (std::rand() % 40) / 100.0f, 0.0f);
        float lifetime = 0.8f + (std::rand() % 60) / 100.0f;
        float size = 0.08f + (std::rand() % 40) / 1000.0f;
        
        emitParticle(position, velocity, color, lifetime, size, ParticleType::EXPLOSION);
    }
}

void ParticleSystem::emitParticle(const Vector3& position, const Vector3& velocity, const Vector3& color,
                                  float lifetime, float size, ParticleType type) {
    Particle& p = particles[nextParticleIndex];
    
    p.position = position;
    p.velocity = velocity;
    p.color = color;
    p.lifetime = lifetime;
    p.maxLifetime = lifetime;
    p.size = size;
    p.type = type;
    
    nextParticleIndex = (nextParticleIndex + 1) % maxParticles;
}

void ParticleSystem::update(float deltaTime) {
    for (auto& p : particles) {
        if (p.isAlive()) {
            p.lifetime -= deltaTime;
            p.position += p.velocity * deltaTime;
            
            // Apply gravity (less for smoke)
            if (p.type == ParticleType::SMOKE) {
                p.velocity.y -= 1.0f * deltaTime;
            } else {
                p.velocity.y -= 5.0f * deltaTime;
            }
            
            // Fade out particles as they die
            if (p.type == ParticleType::SMOKE) {
                // Smoke expands and fades
                p.size += 0.05f * deltaTime;
            }
        }
    }
}

int ParticleSystem::getActiveParticleCount() const {
    int count = 0;
    for (const auto& p : particles) {
        if (p.isAlive()) {
            count++;
        }
    }
    return count;
}
