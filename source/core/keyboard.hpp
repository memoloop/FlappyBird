#pragma once
#include <SDL2/SDL_keyboard.h>

class Keyboard {
public:
    static const Uint8* keys;

    static void takeEvents();
    static bool onKeyDown(SDL_Scancode key);
    static bool onKeyUp(SDL_Scancode key);
};