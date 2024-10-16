#include "window.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include "../utils/codeError.hpp"
#include "keyboard.hpp"

Window::Window(int width, int height, const char* title) {
    // Create window
    window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    if(window == nullptr) {
        std::cerr << "Impossible to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        std::exit(Error::CREATE_WINDOW);
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr) {
        std::cerr << "Impossible to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        std::exit(Error::CREATE_RENDERER);
    }
}

Window::~Window() {
    // Destroy window pointer
    SDL_DestroyWindow(window);
    // Destroy renderer
    SDL_DestroyRenderer(renderer);
}

void Window::run(IGame* game, Uint32 delay) {
    game->window = window;
    game->renderer = renderer;

    // On game start
    game->initialize();
    // Game loop
    while(running) {
        // Poll events
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
            // Quit event
            case SDL_QUIT:
                running = false; // Quit loop
                break;
            }
        }
        Keyboard::takeEvents();

        game->update();

        // Clear the window
        SDL_RenderClear(renderer);

        game->draw();

        // Set bg color
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
        // Update window
        SDL_RenderPresent(renderer);

        // Set delay
        SDL_Delay(delay);
    }
    // On exit
    delete game;
}