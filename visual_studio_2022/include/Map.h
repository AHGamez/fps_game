#ifndef MAP_H
#define MAP_H

#include "Vector3.h"
#include "Collision.h"
#include <vector>

struct Wall {
    AABB bounds;
    Vector3 color;
    
    Wall(const AABB& bounds, const Vector3& color) 
        : bounds(bounds), color(color) {}
};

class Map {
public:
    Map();
    
    void generateRoomMap();
    const std::vector<Wall>& getWalls() const { return walls; }
    bool checkCollision(const AABB& playerBox, Vector3& correction) const;
    
private:
    std::vector<Wall> walls;
    void addWall(float x, float y, float z, float width, float height, float depth, 
                 const Vector3& color);
};

#endif // MAP_H
