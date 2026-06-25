#include "DebugHUD.h"
#include "Player.h"
#include <sstream>
#include <iomanip>

DebugHUD::DebugHUD() : enabled(false), fps(0.0f) {
}

void DebugHUD::update(const Player& player, float fps) {
    this->fps = fps;
    
    if (!enabled) {
        debugInfo = "";
        return;
    }
    
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    
    Vector3 pos = player.getPosition();
    Vector3 forward = player.getCamera().getForward();
    
    oss << "=== DEBUG INFO ===\n";
    oss << "FPS: " << fps << "\n";
    oss << "Position: (" << pos.x << ", " << pos.y << ", " << pos.z << ")\n";
    oss << "Forward: (" << forward.x << ", " << forward.y << ", " << forward.z << ")\n";
    oss << "Yaw: " << player.getCamera().getYaw() << " Pitch: " << player.getCamera().getPitch() << "\n";
    oss << "Ammo: " << player.getWeapon().getAmmo() << "/" << player.getWeapon().getMaxAmmo() << "\n";
    
    if (player.getWeapon().isReloading()) {
        oss << "Reloading: " << (player.getWeapon().getReloadProgress() * 100.0f) << "%\n";
    }
    
    debugInfo = oss.str();
}

void DebugHUD::render() const {
    // Rendering is handled by the Renderer class
}
