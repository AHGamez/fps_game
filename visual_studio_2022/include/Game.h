#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Renderer.h"
#include "InputHandler.h"
#include "Player.h"
#include "Map.h"
#include "ParticleSystem.h"
#include "DebugHUD.h"

class Game {
public:
    Game();
    ~Game();
    
    bool initialize();
    void run();
    void shutdown();
    
private:
    void processInput();
    void update(float deltaTime);
    void render();
    
    Window* window;
    Renderer* renderer;
    InputHandler inputHandler;
    Player* player;
    Map* map;
    ParticleSystem* particleSystem;
    DebugHUD* debugHUD;
    
    bool running;
    float fps;
    int frameCount;
    float fpsTimer;
};

#endif // GAME_H
