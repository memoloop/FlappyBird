#include "texture.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>
#include "../utils/codeError.hpp"

Texture::Texture(SDL_Renderer* renderer, const char* filePath) {
    // Load texture from file
    texture = IMG_LoadTexture(renderer, filePath);
    if(texture == nullptr) {
        std::cerr << "Impossible to load texture ('" << filePath << "'): " << IMG_GetError() << std::endl;
        // Create an empty texture if it is impossible to load
        texture = SDL_CreateTexture(
            renderer, 
            SDL_PixelFormatEnum::SDL_PIXELFORMAT_RGBA32,
            SDL_TextureAccess::SDL_TEXTUREACCESS_STATIC,
            1, 1);
        if(texture == nullptr) {
            std::cerr << "Impossible to create an empty texture: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(SDL_RenderGetWindow(renderer));
            SDL_DestroyRenderer(renderer);
            std::exit(Error::LOAD_TEXTURE); // Exit if not create an empty texture
        } 
    }

    // Create rectangle
    rect.x = 0; // default value
    rect.y = 0; // default value
    // Get size of texture
    SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
}

Texture::~Texture() {
    // Destroy texture pointer
    SDL_DestroyTexture(texture);
}

SDL_Texture* Texture::getId() {
    return texture;
}