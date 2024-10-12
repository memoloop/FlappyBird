#pragma once
#include <SDL2/SDL_render.h>

class Texture {
public:
    Texture(SDL_Renderer* renderer, const char* filePath);
    ~Texture();
    
    SDL_Texture* getId(); // return the pointer (SDL_Texture*)

    SDL_Rect rect; // portion of image that will visualized

protected:
    SDL_Texture* texture = nullptr; // texture pointer
};