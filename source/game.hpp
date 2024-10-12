#pragma once
#include "core/iGame.hpp"
#include "graphics/sprite.hpp"

class Game : public IGame {
public:
    Game();
    ~Game() override;

    void initialize() override;
    void update() override;
    void draw() override;
    void cleanUp();

private:
    Sprite* sprite = nullptr;
};