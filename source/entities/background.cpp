#include "background.hpp"
#include "../config.hpp"
#include "../utils/textureLoader.hpp"

Background::Background() : 
    Sprite(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, TextureLoader::textureList["background-day"]) {}

Background::~Background() {}