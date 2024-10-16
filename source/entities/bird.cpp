#include "bird.hpp"
#include "../config.hpp"
#include "../utils/textureLoader.hpp"
#include "../core/keyboard.hpp"

Bird::Bird() : Sprite(50, (WINDOW_HEIGHT-24)/2, 34, 24) {
    // Select only the essential images to create fly animation
    flyFrames = {
        TextureLoader::textureList["yellowbird-downflap"],
        TextureLoader::textureList["yellowbird-midflap"],
        TextureLoader::textureList["yellowbird-upflap"]
    };

    // Set texture
    texture = flyFrames[1]; // midflap
}

Bird::~Bird() {}

void Bird::update() {
    jump();
    fall();

    // change the y position
    rect.y += dy;

    // reset the y position modify
    dy = 0;
}

void Bird::fall() {
    // The bird fall
    // debug: the bird doesn't go out the window
    if(rect.y <= WINDOW_HEIGHT-rect.h)
        dy += gravityForce;
}

void Bird::jump() {
    // if you click space, the bird fly
    if(Keyboard::onKeyDown(SDL_SCANCODE_SPACE) && jumpTime < 1.0f) {
        dy -= jumpForce;
        jumpTime += 0.01f;
    }
    else if(Keyboard::onKeyUp(SDL_SCANCODE_SPACE)) {
        jumpTime = 0;
    }
}