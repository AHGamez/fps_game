#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "Vector3.h"
#include <vector>

struct Particle {
    Vector3 position;
    Vector3 velocity;
    Vector3 color;
    float lifetime;
    float maxLifetime;
    float size;
    
    bool isAlive() const { return lifetime > 0.0f; }
};

class ParticleSystem {
public:
    ParticleSystem(int maxParticles);
    
    void emit(const Vector3& position, const Vector3& direction, int count);
    void update(float deltaTime);
    const std::vector<Particle>& getParticles() const { return particles; }
    
private:
    std::vector<Particle> particles;
    int maxParticles;
    int nextParticleIndex;
};

#endif // PARTICLESYSTEM_H
