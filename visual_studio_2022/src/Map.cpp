#include "Map.h"

Map::Map() {
    generateRoomMap();
}

void Map::generateRoomMap() {
    walls.clear();
    
    // Floor
    addWall(0, -0.5f, 0, 30, 0.5f, 30, Vector3(0.3f, 0.3f, 0.3f));
    
    // Ceiling
    addWall(0, 10, 0, 30, 0.5f, 30, Vector3(0.4f, 0.4f, 0.4f));
    
    // North wall
    addWall(0, 5, -15, 30, 10, 0.5f, Vector3(0.7f, 0.3f, 0.3f));
    
    // South wall
    addWall(0, 5, 15, 30, 10, 0.5f, Vector3(0.3f, 0.7f, 0.3f));
    
    // East wall
    addWall(15, 5, 0, 0.5f, 10, 30, Vector3(0.3f, 0.3f, 0.7f));
    
    // West wall
    addWall(-15, 5, 0, 0.5f, 10, 30, Vector3(0.7f, 0.7f, 0.3f));
    
    // Interior obstacles
    addWall(-5, 1, -5, 2, 2, 2, Vector3(0.8f, 0.4f, 0.2f));
    addWall(5, 1.5f, 5, 3, 3, 3, Vector3(0.2f, 0.8f, 0.4f));
    addWall(0, 0.75f, 8, 4, 1.5f, 1.5f, Vector3(0.6f, 0.2f, 0.8f));
    addWall(-8, 2, 0, 1.5f, 4, 1.5f, Vector3(0.9f, 0.6f, 0.3f));
}

void Map::addWall(float x, float y, float z, float width, float height, float depth,
                  const Vector3& color) {
    Vector3 halfSize(width * 0.5f, height * 0.5f, depth * 0.5f);
    Vector3 center(x, y, z);
    AABB bounds(center - halfSize, center + halfSize);
    walls.emplace_back(bounds, color);
}

bool Map::checkCollision(const AABB& playerBox, Vector3& correction) const {
    bool collided = false;
    correction = Vector3(0, 0, 0);
    
    for (const auto& wall : walls) {
        if (Collision::checkAABB(playerBox, wall.bounds)) {
            Vector3 resolve = Collision::resolveAABB(playerBox, wall.bounds, Vector3(0, 0, 0));
            correction += resolve;
            collided = true;
        }
    }
    
    return collided;
}
