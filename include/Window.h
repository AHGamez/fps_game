#ifndef WINDOW_H
#define WINDOW_H

#include "SDL.h"
#include <string>

class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();
    
    bool initialize();
    void swapBuffers();
    SDL_Window* getSDLWindow() const { return window; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    
private:
    SDL_Window* window;
    SDL_GLContext glContext;
    std::string title;
    int width;
    int height;
};

#endif // WINDOW_H
