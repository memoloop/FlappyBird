#pragma once
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include "texture.hpp"

class Sprite {
public:
    Sprite(int x, int y, int width, int height, Texture* texture=nullptr);
    virtual ~Sprite();

    virtual void draw(SDL_Renderer* renderer, SDL_Color color={255, 255, 255, 255});
    
    SDL_Rect rect;

protected:
    Texture* texture = nullptr;
};