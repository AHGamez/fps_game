#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3.h"

class Camera {
public:
    Camera(const Vector3& position, float yaw, float pitch);
    
    void update(float deltaTime);
    void rotate(float dyaw, float dpitch);
    void move(const Vector3& offset);
    
    Vector3 getPosition() const { return position; }
    Vector3 getForward() const { return forward; }
    Vector3 getRight() const { return right; }
    Vector3 getUp() const { return up; }
    
    float getYaw() const { return yaw; }
    float getPitch() const { return pitch; }
    
    void setPosition(const Vector3& pos) { position = pos; }
    
private:
    void updateVectors();
    
    Vector3 position;
    Vector3 forward;
    Vector3 right;
    Vector3 up;
    
    float yaw;
    float pitch;
};

#endif // CAMERA_H
