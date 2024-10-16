#include "base.hpp"
#include "../config.hpp"
#include "../utils/textureLoader.hpp"

Base::Base(BaseOrder baseOrder) : Sprite(0, WINDOW_HEIGHT-100, WINDOW_WIDTH, 100, TextureLoader::textureList["base"]) {
    // Set out the screen, if it is last
    if(baseOrder == BaseOrder::LAST) {
        rect.x = WINDOW_WIDTH;
    }

    this->baseOrder = baseOrder;
}

Base::~Base() {}

void Base::update() {
    move();

    rect.x += dx;
    dx = 0;
}

void Base::move() {
    // The base doesn't exit from the screen
    switch(baseOrder) {
    case FIRST:
        if(rect.x+rect.w < 0) {
            rect.x = 0;
        }
        break;
    case LAST:
        if(rect.x+rect.w < WINDOW_WIDTH) {
            rect.x = WINDOW_WIDTH;
        }
        break;
    default: break;
    }
    
    dx += speed;
}