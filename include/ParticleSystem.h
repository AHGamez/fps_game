#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "Vector3.h"
#include <vector>

enum class ParticleType {
    MUZZLE_FLASH,
    SPARK,
    SMOKE,
    EXPLOSION
};

struct Particle {
    Vector3 position;
    Vector3 velocity;
    Vector3 color;
    float lifetime;
    float maxLifetime;
    float size;
    ParticleType type;
    
    bool isAlive() const { return lifetime > 0.0f; }
};

class ParticleSystem {
public:
    ParticleSystem(int maxParticles);
    
    void emit(const Vector3& position, const Vector3& direction, int count);
    void emitTyped(const Vector3& position, const Vector3& direction, int count, ParticleType type);
    void emitExplosion(const Vector3& position, int count);
    void update(float deltaTime);
    const std::vector<Particle>& getParticles() const { return particles; }
    
    int getActiveParticleCount() const;
    int getMaxParticles() const { return maxParticles; }
    
private:
    void emitParticle(const Vector3& position, const Vector3& velocity, const Vector3& color, 
                     float lifetime, float size, ParticleType type);
    
    std::vector<Particle> particles;
    int maxParticles;
    int nextParticleIndex;
};

#endif // PARTICLESYSTEM_H
