#include "keyboard.hpp"

const Uint8* Keyboard::keys = nullptr;

void Keyboard::takeEvents() {
    // Get the states of keys
    keys = SDL_GetKeyboardState(nullptr);
}

bool Keyboard::onKeyDown(SDL_Scancode key) {
    return keys[key];
}

bool Keyboard::onKeyUp(SDL_Scancode key) {
    return !keys[key];
}