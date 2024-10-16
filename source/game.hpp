#pragma once
#include "core/iGame.hpp"
#include "entities/bird.hpp"
#include "entities/base.hpp"

class Game : public IGame {
public:
    Game();
    ~Game() override;

    void initialize() override;
    void update() override;
    void draw() override;
    void cleanUp();

private:
    Bird* bird = nullptr;
    Base* base1 = nullptr;
    Base* base2 = nullptr;
};