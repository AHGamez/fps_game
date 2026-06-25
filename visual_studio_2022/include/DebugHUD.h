#ifndef DEBUGHUD_H
#define DEBUGHUD_H

#include "Vector3.h"
#include <string>
#include <vector>

class Player;

struct PerformanceMetrics {
    float minFPS;
    float maxFPS;
    float avgFPS;
    int totalFrames;
    float totalTime;
};

class DebugHUD {
public:
    DebugHUD();
    
    void toggle() { enabled = !enabled; }
    bool isEnabled() const { return enabled; }
    
    void update(const Player& player, float fps);
    void render() const;
    
    std::string getDebugInfo() const { return debugInfo; }
    const PerformanceMetrics& getMetrics() const { return metrics; }
    
    void resetMetrics();
    void addFrameTime(float frameTime);
    
private:
    bool enabled;
    std::string debugInfo;
    float fps;
    PerformanceMetrics metrics;
    std::vector<float> recentFrameTimes;
    const int maxFrameTimesSamples = 60;
};

#endif // DEBUGHUD_H
