#include "DebugHUD.h"
#include "Player.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>

DebugHUD::DebugHUD() : enabled(false), fps(0.0f) {
    resetMetrics();
}

void DebugHUD::update(const Player& player, float fps) {
    this->fps = fps;
    
    // Update performance metrics
    metrics.totalFrames++;
    if (fps < metrics.minFPS || metrics.minFPS == 0.0f) {
        metrics.minFPS = fps;
    }
    if (fps > metrics.maxFPS) {
        metrics.maxFPS = fps;
    }
    
    if (!enabled) {
        debugInfo = "";
        return;
    }
    
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    
    Vector3 pos = player.getPosition();
    Vector3 forward = player.getCamera().getForward();
    Vector3 velocity = player.getCamera().getPosition() - player.getPosition();
    
    oss << "=== ENHANCED DEBUG INFO ===\n";
    oss << "FPS: " << fps << " (Min: " << metrics.minFPS << ", Max: " << metrics.maxFPS << ")\n";
    
    // Calculate average FPS from recent frame times
    if (!recentFrameTimes.empty()) {
        float avgFrameTime = std::accumulate(recentFrameTimes.begin(), recentFrameTimes.end(), 0.0f) / recentFrameTimes.size();
        oss << "Avg Frame Time: " << (avgFrameTime * 1000.0f) << "ms\n";
    }
    
    oss << "\n=== PLAYER INFO ===\n";
    oss << "Position: (" << pos.x << ", " << pos.y << ", " << pos.z << ")\n";
    oss << "Forward: (" << forward.x << ", " << forward.y << ", " << forward.z << ")\n";
    oss << "Yaw: " << player.getCamera().getYaw() << " Pitch: " << player.getCamera().getPitch() << "\n";
    
    oss << "\n=== WEAPON INFO ===\n";
    oss << "Ammo: " << player.getWeapon().getAmmo() << "/" << player.getWeapon().getMaxAmmo() << "\n";
    
    if (player.getWeapon().isReloading()) {
        oss << "Reloading: " << (player.getWeapon().getReloadProgress() * 100.0f) << "%\n";
    } else {
        oss << "Cooldown: " << (player.getWeapon().getCooldownProgress() * 100.0f) << "%\n";
    }
    
    oss << "\n=== PERFORMANCE ===\n";
    oss << "Total Frames: " << metrics.totalFrames << "\n";
    oss << "Session Time: " << metrics.totalTime << "s\n";
    
    debugInfo = oss.str();
}

void DebugHUD::render() const {
    // Rendering is handled by the Renderer class
}

void DebugHUD::resetMetrics() {
    metrics.minFPS = 0.0f;
    metrics.maxFPS = 0.0f;
    metrics.avgFPS = 0.0f;
    metrics.totalFrames = 0;
    metrics.totalTime = 0.0f;
    recentFrameTimes.clear();
}

void DebugHUD::addFrameTime(float frameTime) {
    metrics.totalTime += frameTime;
    
    recentFrameTimes.push_back(frameTime);
    if (recentFrameTimes.size() > maxFrameTimesSamples) {
        recentFrameTimes.erase(recentFrameTimes.begin());
    }
}
