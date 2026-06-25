#ifndef PLAYER_H
#define PLAYER_H

#include "Vector3.h"
#include "Camera.h"
#include "Weapon.h"
#include "Collision.h"

class Player {
public:
    Player(const Vector3& startPosition);
    
    void update(float deltaTime);
    void handleMovement(bool forward, bool backward, bool left, bool right, float deltaTime);
    void handleMouseLook(int dx, int dy, float deltaTime);
    void jump();
    void shoot();
    void reload();
    
    Camera& getCamera() { return camera; }
    const Camera& getCamera() const { return camera; }
    Weapon& getWeapon() { return weapon; }
    const Weapon& getWeapon() const { return weapon; }
    
    AABB getBoundingBox() const;
    void setPosition(const Vector3& pos);
    Vector3 getPosition() const { return position; }
    
private:
    Vector3 position;
    Vector3 velocity;
    Camera camera;
    Weapon weapon;
    
    float moveSpeed;
    float mouseSensitivity;
    float jumpForce;
    float gravity;
    bool onGround;
    
    float playerWidth;
    float playerHeight;
};

#endif // PLAYER_H
