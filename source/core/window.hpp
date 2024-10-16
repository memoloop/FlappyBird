#pragma once
#include <SDL2/SDL_render.h>
#include "iGame.hpp"

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();
    void run(IGame* game, Uint32 delay);

private:
    SDL_Window* window = nullptr;           // window pointer
    SDL_Renderer* renderer = nullptr;       // to draw on window
    bool running = true;
};