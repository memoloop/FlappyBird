#pragma once
#include <iostream>
#include <map>
#include <SDL2/SDL_render.h>
#include "../graphics/texture.hpp"
#include "codeError.hpp"

class TextureLoader {
public:
    static std::map<std::string, Texture*> textureList;

    static void loadTextureInFolder(SDL_Renderer* renderer, const char* folder);
    static void freeAllTexture();
};