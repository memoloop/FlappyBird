#include "sprite.hpp"

Sprite::Sprite(int x, int y, int width, int height, Texture* texture) :
    rect({x, y, width, height}),
    texture(texture) {}

Sprite::~Sprite() {}

void Sprite::draw(SDL_Renderer* renderer, SDL_Color color) {
    // Draw the sprite with the texture
    if(texture != nullptr) {
        SDL_SetTextureColorMod(texture->getId(), color.r, color.g, color.b);
        SDL_SetTextureAlphaMod(texture->getId(), color.a);
        SDL_RenderCopy(renderer, texture->getId(), &texture->rect, &rect);
    } else {
        // Draw a simple rectangle
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(renderer, &rect);
    }
}