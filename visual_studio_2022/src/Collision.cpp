#include "Collision.h"
#include <algorithm>
#include <cmath>

bool Collision::checkAABB(const AABB& a, const AABB& b) {
    return a.intersects(b);
}

Vector3 Collision::resolveAABB(const AABB& moving, const AABB& stationary, const Vector3& velocity) {
    // Calculate overlap on each axis
    float overlapX = std::min(moving.max.x, stationary.max.x) - std::max(moving.min.x, stationary.min.x);
    float overlapY = std::min(moving.max.y, stationary.max.y) - std::max(moving.min.y, stationary.min.y);
    float overlapZ = std::min(moving.max.z, stationary.max.z) - std::max(moving.min.z, stationary.min.z);
    
    // Find the axis with minimum overlap
    Vector3 correction(0, 0, 0);
    
    if (overlapX < overlapY && overlapX < overlapZ) {
        // Resolve on X axis
        correction.x = (velocity.x > 0) ? -overlapX : overlapX;
    } else if (overlapY < overlapZ) {
        // Resolve on Y axis
        correction.y = (velocity.y > 0) ? -overlapY : overlapY;
    } else {
        // Resolve on Z axis
        correction.z = (velocity.z > 0) ? -overlapZ : overlapZ;
    }
    
    return correction;
}
