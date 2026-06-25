#include "Renderer.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <sstream>
#include <iomanip>

Renderer::Renderer(int width, int height) : width(width), height(height) {
}

void Renderer::initialize() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    
    setViewport(width, height);
}

void Renderer::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::render(const Camera& camera, const Map& map, const Player& player,
                      const ParticleSystem& particles, const DebugHUD& debugHUD, float fps) {
    // Setup 3D rendering
    setupPerspective();
    setupCamera(camera);
    
    // Render 3D world
    renderMap(map);
    renderParticles(particles);
    
    // Setup 2D rendering for HUD
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glDisable(GL_DEPTH_TEST);
    
    // Render HUD elements
    renderCrosshair();
    renderHUD(player, fps);
    
    if (debugHUD.isEnabled()) {
        renderDebugHUD(debugHUD);
    }
    
    glEnable(GL_DEPTH_TEST);
}

void Renderer::setupPerspective() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75.0, (double)width / (double)height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void Renderer::setupCamera(const Camera& camera) {
    glLoadIdentity();
    
    Vector3 pos = camera.getPosition();
    Vector3 forward = camera.getForward();
    Vector3 up = camera.getUp();
    Vector3 target = pos + forward;
    
    gluLookAt(pos.x, pos.y, pos.z,
              target.x, target.y, target.z,
              up.x, up.y, up.z);
}

void Renderer::renderMap(const Map& map) {
    for (const auto& wall : map.getWalls()) {
        glColor3f(wall.color.x, wall.color.y, wall.color.z);
        
        const AABB& bounds = wall.bounds;
        
        glBegin(GL_QUADS);
        
        // Front face
        glVertex3f(bounds.min.x, bounds.min.y, bounds.max.z);
        glVertex3f(bounds.max.x, bounds.min.y, bounds.max.z);
        glVertex3f(bounds.max.x, bounds.max.y, bounds.max.z);
        glVertex3f(bounds.min.x, bounds.max.y, bounds.max.z);
        
        // Back face
        glVertex3f(bounds.min.x, bounds.min.y, bounds.min.z);
        glVertex3f(bounds.min.x, bounds.max.y, bounds.min.z);
        glVertex3f(bounds.max.x, bounds.max.y, bounds.min.z);
        glVertex3f(bounds.max.x, bounds.min.y, bounds.min.z);
        
        // Left face
        glVertex3f(bounds.min.x, bounds.min.y, bounds.min.z);
        glVertex3f(bounds.min.x, bounds.min.y, bounds.max.z);
        glVertex3f(bounds.min.x, bounds.max.y, bounds.max.z);
        glVertex3f(bounds.min.x, bounds.max.y, bounds.min.z);
        
        // Right face
        glVertex3f(bounds.max.x, bounds.min.y, bounds.min.z);
        glVertex3f(bounds.max.x, bounds.max.y, bounds.min.z);
        glVertex3f(bounds.max.x, bounds.max.y, bounds.max.z);
        glVertex3f(bounds.max.x, bounds.min.y, bounds.max.z);
        
        // Top face
        glVertex3f(bounds.min.x, bounds.max.y, bounds.min.z);
        glVertex3f(bounds.min.x, bounds.max.y, bounds.max.z);
        glVertex3f(bounds.max.x, bounds.max.y, bounds.max.z);
        glVertex3f(bounds.max.x, bounds.max.y, bounds.min.z);
        
        // Bottom face
        glVertex3f(bounds.min.x, bounds.min.y, bounds.min.z);
        glVertex3f(bounds.max.x, bounds.min.y, bounds.min.z);
        glVertex3f(bounds.max.x, bounds.min.y, bounds.max.z);
        glVertex3f(bounds.min.x, bounds.min.y, bounds.max.z);
        
        glEnd();
    }
}

void Renderer::renderCrosshair() {
    float centerX = width / 2.0f;
    float centerY = height / 2.0f;
    float size = 10.0f;
    float gap = 5.0f;
    
    glColor3f(0.0f, 1.0f, 0.0f);
    glLineWidth(2.0f);
    
    glBegin(GL_LINES);
    // Horizontal line
    glVertex2f(centerX - size - gap, centerY);
    glVertex2f(centerX - gap, centerY);
    glVertex2f(centerX + gap, centerY);
    glVertex2f(centerX + size + gap, centerY);
    
    // Vertical line
    glVertex2f(centerX, centerY - size - gap);
    glVertex2f(centerX, centerY - gap);
    glVertex2f(centerX, centerY + gap);
    glVertex2f(centerX, centerY + size + gap);
    glEnd();
    
    glLineWidth(1.0f);
}

void Renderer::renderHUD(const Player& player, float fps) {
    std::ostringstream oss;
    oss << "FPS: " << std::fixed << std::setprecision(0) << fps;
    renderText(oss.str(), 10, 20);
    
    oss.str("");
    oss << "Ammo: " << player.getWeapon().getAmmo() << "/" << player.getWeapon().getMaxAmmo();
    renderText(oss.str(), 10, 40);
    
    if (player.getWeapon().isReloading()) {
        renderText("RELOADING...", 10, 60);
        
        // Reload progress bar
        float progress = player.getWeapon().getReloadProgress();
        float barWidth = 200.0f;
        float barHeight = 20.0f;
        float x = 10;
        float y = 70;
        
        // Background
        glColor3f(0.2f, 0.2f, 0.2f);
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + barWidth, y);
        glVertex2f(x + barWidth, y + barHeight);
        glVertex2f(x, y + barHeight);
        glEnd();
        
        // Progress
        glColor3f(0.0f, 0.8f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + barWidth * progress, y);
        glVertex2f(x + barWidth * progress, y + barHeight);
        glVertex2f(x, y + barHeight);
        glEnd();
    }
    
    renderText("Press F1 for Debug Info", 10, height - 40);
    renderText("Controls: WASD=Move, Mouse=Look, LMB=Shoot, R=Reload, Space=Jump", 10, height - 20);
}

void Renderer::renderDebugHUD(const DebugHUD& debugHUD) {
    std::string info = debugHUD.getDebugInfo();
    float y = 100.0f;
    
    glColor3f(1.0f, 1.0f, 0.0f);
    
    std::istringstream stream(info);
    std::string line;
    while (std::getline(stream, line)) {
        renderText(line, 10, y);
        y += 15;
    }
}

void Renderer::renderParticles(const ParticleSystem& particles) {
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    
    glBegin(GL_QUADS);
    for (const auto& p : particles.getParticles()) {
        if (p.isAlive()) {
            float alpha = p.lifetime / p.maxLifetime;
            glColor4f(p.color.x, p.color.y, p.color.z, alpha);
            
            // Billboard quad facing camera
            float s = p.size;
            glVertex3f(p.position.x - s, p.position.y - s, p.position.z);
            glVertex3f(p.position.x + s, p.position.y - s, p.position.z);
            glVertex3f(p.position.x + s, p.position.y + s, p.position.z);
            glVertex3f(p.position.x - s, p.position.y + s, p.position.z);
        }
    }
    glEnd();
    
    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
}

void Renderer::renderText(const std::string& text, float x, float y, float scale) {
    // Simple text rendering using basic OpenGL
    // This is a placeholder - in a production game you'd use a proper font library
    glColor3f(1.0f, 1.0f, 1.0f);
    
    // For now, we'll just render a simple debug indicator
    // A proper implementation would use texture-based fonts or a library like FreeType
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + 5, y);
    glVertex2f(x + 5, y + 10);
    glVertex2f(x, y + 10);
    glEnd();
}

void Renderer::setViewport(int width, int height) {
    this->width = width;
    this->height = height;
    glViewport(0, 0, width, height);
}
