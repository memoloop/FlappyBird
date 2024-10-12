#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "utils/codeError.hpp"
#include "core/window.hpp"
#include "game.hpp"

#ifdef __cplusplus
extern "C"
#endif
int main(int argc, char* argv[]) {
    // Initialize SDL2
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Impossible to initialize SDL2: " << SDL_GetError() << std::endl;
        return Error::INIT_SDL2;
    }

    // Initialize SDL2_image
    if(IMG_Init(IMG_INIT_PNG) < 0) {
        std::cerr << "Impossible to initialize SDL2 image: " << SDL_GetError() << std::endl;
        return Error::INIT_SDL2_IMAGE;
    }

    Window window(1600, 900, "game");
    window.run(new Game());

    // Quit SDL2
    SDL_Quit();
    // Quit SDL2 image
    IMG_Quit();

    return Error::NO;
}