#ifndef RENDERER_H
#define RENDERER_H

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

#include "Camera.h"
#include "Map.h"
#include "Player.h"
#include "ParticleSystem.h"
#include "DebugHUD.h"
#include <string>

class Renderer {
public:
    Renderer(int width, int height);

    void initialize();
    void clear();
    void render(const Camera& camera, const Map& map, const Player& player,
                const ParticleSystem& particles, const DebugHUD& debugHUD, float fps);
    void setViewport(int width, int height);

    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    int width;
    int height;

    void setupPerspective();
    void setupCamera(const Camera& camera);
    void renderMap(const Map& map);
    void renderParticles(const ParticleSystem& particles);
    void renderCrosshair();
    void renderHUD(const Player& player, float fps);
    void renderDebugHUD(const DebugHUD& debugHUD);
    void renderText(const std::string& text, float x, float y, float scale = 1.0f);
};

#endif // RENDERER_H
