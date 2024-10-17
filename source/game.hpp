#pragma once
#include "core/iGame.hpp"
#include "entities/bird.hpp"
#include "entities/base.hpp"
#include "entities/background.hpp"

class Game : public IGame {
public:
    Game();
    ~Game() override;

    void initialize() override;
    void update() override;
    void draw() override;
    void cleanUp();

    static Bird* bird;
    static Base* base1;
    static Base* base2;
    static Background* bg;
};