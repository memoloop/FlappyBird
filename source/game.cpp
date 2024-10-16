#include "game.hpp"
#include <iostream>
#include "utils/textureLoader.hpp"

Game::Game() {}

Game::~Game() {
    cleanUp();
}

void Game::initialize() {
    TextureLoader::loadTextureInFolder(renderer, "assets/sprites");
    bird = new Bird();
    base1 = new Base(BaseOrder::FIRST);
    base2 = new Base(BaseOrder::LAST);
}

void Game::update() {
    bird->update();
    base1->update();
    base2->update();
}

void Game::draw() {
    bird->draw(renderer);
    base1->draw(renderer);
    base2->draw(renderer);
}

void Game::cleanUp() {
    delete bird;
    delete base1;
    delete base2;
    TextureLoader::freeAllTexture();
}