#include "Game.h"
#include <iostream>
#include "SDL.h"

Game::Game()
    : window(nullptr), renderer(nullptr), player(nullptr), map(nullptr),
      particleSystem(nullptr), debugHUD(nullptr), running(false),
      fps(0.0f), frameCount(0), fpsTimer(0.0f) {
}

Game::~Game() {
    shutdown();
}

bool Game::initialize() {
    window = new Window("FPS Game", 1280, 720);
    if (!window->initialize()) {
        std::cerr << "Failed to initialize window" << std::endl;
        return false;
    }
    
    renderer = new Renderer(1280, 720);
    renderer->initialize();
    
    player = new Player(Vector3(0, 0, 0));
    map = new Map();
    particleSystem = new ParticleSystem(1000);
    debugHUD = new DebugHUD();
    
    running = true;
    return true;
}

void Game::run() {
    const float TARGET_FPS = 60.0f;
    const float FIXED_TIMESTEP = 1.0f / TARGET_FPS;
    
    Uint32 lastTime = SDL_GetTicks();
    float accumulator = 0.0f;
    
    while (running) {
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;
        
        // Cap delta time to prevent spiral of death
        if (deltaTime > 0.25f) {
            deltaTime = 0.25f;
        }
        
        accumulator += deltaTime;
        
        // Track frame time for debug HUD
        debugHUD->addFrameTime(deltaTime);
        
        // Fixed timestep update
        while (accumulator >= FIXED_TIMESTEP) {
            processInput();
            update(FIXED_TIMESTEP);
            accumulator -= FIXED_TIMESTEP;
        }
        
        // FPS calculation
        frameCount++;
        fpsTimer += deltaTime;
        if (fpsTimer >= 1.0f) {
            fps = frameCount / fpsTimer;
            frameCount = 0;
            fpsTimer = 0.0f;
        }
        
        // Render
        renderer->clear();
        render();
        window->swapBuffers();
    }
}

void Game::processInput() {
    inputHandler.update();
    
    if (inputHandler.shouldQuit() || inputHandler.isKeyPressed(SDLK_ESCAPE)) {
        running = false;
        return;
    }
    
    // Toggle debug HUD
    if (inputHandler.isKeyJustPressed(SDLK_F1)) {
        debugHUD->toggle();
    }
    
    // Movement
    bool forward = inputHandler.isKeyPressed(SDLK_w);
    bool backward = inputHandler.isKeyPressed(SDLK_s);
    bool left = inputHandler.isKeyPressed(SDLK_a);
    bool right = inputHandler.isKeyPressed(SDLK_d);
    
    player->handleMovement(forward, backward, left, right, 0.016f);
    
    // Mouse look
    int dx, dy;
    inputHandler.getMouseDelta(dx, dy);
    player->handleMouseLook(dx, dy, 0.016f);
    
    // Jump
    if (inputHandler.isKeyJustPressed(SDLK_SPACE)) {
        player->jump();
    }
    
    // Shoot
    if (inputHandler.isMouseButtonJustPressed(SDL_BUTTON_LEFT)) {
        if (player->getWeapon().canFire()) {
            player->shoot();
            // Emit enhanced particles
            Vector3 shootPos = player->getCamera().getPosition() + 
                              player->getCamera().getForward() * 0.5f;
            // Muzzle flash
            particleSystem->emitTyped(shootPos, player->getCamera().getForward(), 8, ParticleType::MUZZLE_FLASH);
            // Sparks
            particleSystem->emitTyped(shootPos, player->getCamera().getForward(), 5, ParticleType::SPARK);
            // Smoke trail
            particleSystem->emitTyped(shootPos, player->getCamera().getForward(), 3, ParticleType::SMOKE);
        }
    }
    
    // Reload
    if (inputHandler.isKeyJustPressed(SDLK_r)) {
        player->reload();
    }
}

void Game::update(float deltaTime) {
    player->update(deltaTime);
    
    // Collision detection and resolution
    AABB playerBox = player->getBoundingBox();
    Vector3 correction;
    if (map->checkCollision(playerBox, correction)) {
        Vector3 newPos = player->getPosition() + correction;
        player->setPosition(newPos);
    }
    
    particleSystem->update(deltaTime);
    debugHUD->update(*player, fps);
}

void Game::render() {
    renderer->render(player->getCamera(), *map, *player, *particleSystem, *debugHUD, fps);
}

void Game::shutdown() {
    delete debugHUD;
    delete particleSystem;
    delete map;
    delete player;
    delete renderer;
    delete window;
    
    SDL_Quit();
}
