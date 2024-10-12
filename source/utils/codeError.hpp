#pragma once

/**
 * This enum contains all code errors of this game
 */
enum Error {
    NO,                 // no errors
    INIT_SDL2,          // error when don't initialize SDL2
    INIT_SDL2_IMAGE,    // error when don't initialize SDL2_image
    CREATE_WINDOW,      // error when don't create window
    CREATE_RENDERER,    // error when don't create renderer
    LOAD_TEXTURE,       // error when it's impossible load and create texture
    FOLDER_NOT_FOUND,   // error when the folder did find
};