#pragma once
#include <SDL2/SDL_render.h>

/**
 * Interface that contains Game methods
 */
class IGame {
public:
    virtual void initialize() = 0;                  // On start the game
    virtual void update() = 0;                      // In loop
    virtual void draw() = 0;                        // To draw (always in loop)
    virtual ~IGame() {}                             // Destructor

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};