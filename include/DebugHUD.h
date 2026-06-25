#ifndef DEBUGHUD_H
#define DEBUGHUD_H

#include "Vector3.h"
#include <string>

class Player;

class DebugHUD {
public:
    DebugHUD();
    
    void toggle() { enabled = !enabled; }
    bool isEnabled() const { return enabled; }
    
    void update(const Player& player, float fps);
    void render() const;
    
    std::string getDebugInfo() const { return debugInfo; }
    
private:
    bool enabled;
    std::string debugInfo;
    float fps;
};

#endif // DEBUGHUD_H
