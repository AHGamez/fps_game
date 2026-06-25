#include "Camera.h"
#include <cmath>

Camera::Camera(const Vector3& position, float yaw, float pitch)
    : position(position), yaw(yaw), pitch(pitch) {
    updateVectors();
}

void Camera::update(float deltaTime) {
    // Camera update logic if needed
}

void Camera::rotate(float dyaw, float dpitch) {
    yaw += dyaw;
    pitch += dpitch;
    
    // Clamp pitch to prevent gimbal lock
    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;
    
    updateVectors();
}

void Camera::move(const Vector3& offset) {
    position += offset;
}

void Camera::updateVectors() {
    // Convert to radians
    float yawRad = yaw * 3.14159265f / 180.0f;
    float pitchRad = pitch * 3.14159265f / 180.0f;
    
    // Calculate forward vector
    forward.x = cos(pitchRad) * cos(yawRad);
    forward.y = sin(pitchRad);
    forward.z = cos(pitchRad) * sin(yawRad);
    forward.normalize();
    
    // Calculate right vector
    Vector3 worldUp(0, 1, 0);
    right = forward.cross(worldUp).normalized();
    
    // Calculate up vector
    up = right.cross(forward).normalized();
}
