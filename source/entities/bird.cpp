#include "bird.hpp"
#include "../config.hpp"
#include "../utils/textureLoader.hpp"
#include "../core/keyboard.hpp"
#include "../game.hpp"

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
    flyAnimation();
    collisionWithBase();

    // change the y position
    rect.y += dy;

    // reset the y position modify
    dy = 0;
}

void Bird::fall() {
    // The bird fall
    dy += gravityForce;
}

void Bird::jump() {
    // if you click space, the bird fly
    if(Keyboard::onKeyDown(SDL_SCANCODE_SPACE) && jumpTime < 1.0f) {
        dy -= jumpForce;
        jumpTime += 0.02f;
    }
    else if(Keyboard::onKeyUp(SDL_SCANCODE_SPACE)) {
        jumpTime = 0;
    }
}

void Bird::flyAnimation() {
    // Down flap
    if(dy < 0) {
        texture = flyFrames[0];
    }
    // Fly
    else if(dy > 0) {
        // Mid flap
        if(animationTime < 1.0f) {
            texture = flyFrames[1];
            animationTime += 0.1f;
        }
        // Up flap
        else if(animationTime > 1.0f && animationTime < 2.0f) {
            texture = flyFrames[2];
            animationTime += 0.1f;
        }
        // Reset timer
        else if(animationTime >= 2.0f) {
            animationTime = 0;
        }
    }
}

bool Bird::collisionWithBase(bool solid) {
    // Collision with bases
    if((SDL_HasIntersection(&rect, &Game::base1->rect) ||
       SDL_HasIntersection(&rect, &Game::base2->rect)) &&
       solid) {
        dy = -1;
    }

    return true;
}