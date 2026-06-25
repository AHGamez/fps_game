#ifndef COLLISION_H
#define COLLISION_H

#include "Vector3.h"

struct AABB {
    Vector3 min;
    Vector3 max;
    
    AABB() {}
    AABB(const Vector3& min, const Vector3& max) : min(min), max(max) {}
    
    bool intersects(const AABB& other) const {
        return (min.x <= other.max.x && max.x >= other.min.x) &&
               (min.y <= other.max.y && max.y >= other.min.y) &&
               (min.z <= other.max.z && max.z >= other.min.z);
    }
    
    bool contains(const Vector3& point) const {
        return (point.x >= min.x && point.x <= max.x) &&
               (point.y >= min.y && point.y <= max.y) &&
               (point.z >= min.z && point.z <= max.z);
    }
};

class Collision {
public:
    static bool checkAABB(const AABB& a, const AABB& b);
    static Vector3 resolveAABB(const AABB& moving, const AABB& stationary, const Vector3& velocity);
};

#endif // COLLISION_H
