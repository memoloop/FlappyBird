#include "game.hpp"
#include <iostream>
#include "utils/textureLoader.hpp"

Game::Game() {}

Game::~Game() {
    cleanUp();
}

void Game::initialize() {
    TextureLoader::loadTextureInFolder(renderer, "assets/sprites");
    sprite = new Sprite(0, 0, 100, 100, TextureLoader::textureList["0"]);
}

void Game::update() {

}

void Game::draw() {
    sprite->draw(renderer, {255, 255, 255, 255});
}

void Game::cleanUp() {
    delete sprite;
    TextureLoader::freeAllTexture();
}