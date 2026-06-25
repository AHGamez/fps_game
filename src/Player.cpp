#include "Player.h"
#include <cmath>

Player::Player(const Vector3& startPosition)
    : position(startPosition), velocity(0, 0, 0),
      camera(startPosition + Vector3(0, 1.6f, 0), -90.0f, 0.0f),
      weapon(5.0f, 30),
      moveSpeed(5.0f), mouseSensitivity(0.1f), jumpForce(7.0f), gravity(-20.0f),
      onGround(false), playerWidth(0.8f), playerHeight(1.8f) {
}

void Player::update(float deltaTime) {
    // Apply gravity
    velocity.y += gravity * deltaTime;
    
    // Update position
    position += velocity * deltaTime;
    
    // Ground check (simple)
    if (position.y <= 0) {
        position.y = 0;
        velocity.y = 0;
        onGround = true;
    } else {
        onGround = false;
    }
    
    // Update camera position
    camera.setPosition(position + Vector3(0, 1.6f, 0));
    camera.update(deltaTime);
    
    // Update weapon
    weapon.update(deltaTime);
}

void Player::handleMovement(bool forward, bool backward, bool left, bool right, float deltaTime) {
    Vector3 moveDir(0, 0, 0);
    
    if (forward) moveDir += camera.getForward();
    if (backward) moveDir -= camera.getForward();
    if (right) moveDir += camera.getRight();
    if (left) moveDir -= camera.getRight();
    
    // Zero out Y component for horizontal movement
    moveDir.y = 0;
    if (moveDir.lengthSquared() > 0) {
        moveDir.normalize();
    }
    
    velocity.x = moveDir.x * moveSpeed;
    velocity.z = moveDir.z * moveSpeed;
}

void Player::handleMouseLook(int dx, int dy, float deltaTime) {
    camera.rotate(dx * mouseSensitivity, -dy * mouseSensitivity);
}

void Player::jump() {
    if (onGround) {
        velocity.y = jumpForce;
    }
}

void Player::shoot() {
    weapon.fire();
}

void Player::reload() {
    weapon.reload();
}

AABB Player::getBoundingBox() const {
    float halfWidth = playerWidth * 0.5f;
    Vector3 min(position.x - halfWidth, position.y, position.z - halfWidth);
    Vector3 max(position.x + halfWidth, position.y + playerHeight, position.z + halfWidth);
    return AABB(min, max);
}

void Player::setPosition(const Vector3& pos) {
    position = pos;
    camera.setPosition(position + Vector3(0, 1.6f, 0));
}
