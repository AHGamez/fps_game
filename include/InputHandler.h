#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "SDL.h"

class InputHandler {
public:
    InputHandler();
    
    void update();
    bool isKeyPressed(SDL_Keycode key) const;
    bool isKeyJustPressed(SDL_Keycode key) const;
    bool isMouseButtonPressed(int button) const;
    bool isMouseButtonJustPressed(int button) const;
    
    void getMouseDelta(int& dx, int& dy) const;
    bool shouldQuit() const { return quit; }
    
private:
    const Uint8* keyboardState;
    Uint8 previousKeyboardState[SDL_NUM_SCANCODES];
    Uint32 mouseState;
    Uint32 previousMouseState;
    int mouseDeltaX;
    int mouseDeltaY;
    bool quit;
};

#endif // INPUTHANDLER_H
