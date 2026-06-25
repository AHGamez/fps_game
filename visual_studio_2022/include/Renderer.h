#ifndef RENDERER_H
#define RENDERER_H

#include "Camera.h"
#include "Map.h"
#include "Player.h"
#include "ParticleSystem.h"
#include "DebugHUD.h"

class Renderer {
public:
    Renderer(int width, int height);
    
    void initialize();
    void clear();
    void render(const Camera& camera, const Map& map, const Player& player, 
                const ParticleSystem& particles, const DebugHUD& debugHUD, float fps);
    void setViewport(int width, int height);
    
private:
    void setupPerspective();
    void setupCamera(const Camera& camera);
    void renderMap(const Map& map);
    void renderCrosshair();
    void renderHUD(const Player& player, float fps);
    void renderDebugHUD(const DebugHUD& debugHUD);
    void renderParticles(const ParticleSystem& particles);
    void renderText(const std::string& text, float x, float y, float scale = 1.0f);
    
    int width;
    int height;
};

#endif // RENDERER_H
