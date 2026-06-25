#include "InputHandler.h"
#include <cstring>

InputHandler::InputHandler()
    : keyboardState(nullptr), mouseState(0), previousMouseState(0),
      mouseDeltaX(0), mouseDeltaY(0), quit(false) {
    keyboardState = SDL_GetKeyboardState(nullptr);
    std::memset(previousKeyboardState, 0, sizeof(previousKeyboardState));
}

void InputHandler::update() {
    // Store previous states
    std::memcpy(previousKeyboardState, keyboardState, SDL_NUM_SCANCODES);
    previousMouseState = mouseState;
    
    // Update current states
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit = true;
        }
    }
    
    keyboardState = SDL_GetKeyboardState(nullptr);
    mouseState = SDL_GetMouseState(nullptr, nullptr);
    SDL_GetRelativeMouseState(&mouseDeltaX, &mouseDeltaY);
}

bool InputHandler::isKeyPressed(SDL_Keycode key) const {
    SDL_Scancode scancode = SDL_GetScancodeFromKey(key);
    return keyboardState[scancode];
}

bool InputHandler::isKeyJustPressed(SDL_Keycode key) const {
    SDL_Scancode scancode = SDL_GetScancodeFromKey(key);
    return keyboardState[scancode] && !previousKeyboardState[scancode];
}

bool InputHandler::isMouseButtonPressed(int button) const {
    return (mouseState & SDL_BUTTON(button)) != 0;
}

bool InputHandler::isMouseButtonJustPressed(int button) const {
    return (mouseState & SDL_BUTTON(button)) && !(previousMouseState & SDL_BUTTON(button));
}

void InputHandler::getMouseDelta(int& dx, int& dy) const {
    dx = mouseDeltaX;
    dy = mouseDeltaY;
}
