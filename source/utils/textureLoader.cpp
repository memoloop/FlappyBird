#include "textureLoader.hpp"
#include <filesystem>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace fs = std::filesystem;

std::map<std::string, Texture*> TextureLoader::textureList;

void TextureLoader::loadTextureInFolder(SDL_Renderer* renderer, const char* folder) {
    fs::path directory = folder;

    // Check if exist the directory or if it is a directory
    if(!fs::exists(directory) || !fs::is_directory(directory)) {
        std::cerr << "Impossible to find folder '" << folder << "': " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(SDL_RenderGetWindow(renderer));
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
        IMG_Quit();
        std::exit(Error::FOLDER_NOT_FOUND);
    }

    // Check all files in directory
    for(const auto& file : fs::directory_iterator(directory)) {
        if(fs::is_regular_file(file)) {
            std::string name = file.path().stem().string();
            Texture* texture = new Texture(renderer, 
                (std::string(folder)+"/"+file.path().filename().string()).c_str());
            textureList[name] = texture;
        }
    }
}

void TextureLoader::freeAllTexture() {
    for(auto& texture : textureList) {
        delete texture.second;
        texture.second = nullptr;
        textureList.erase(texture.first);
    }
}