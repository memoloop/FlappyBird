#pragma once
#include "../graphics/sprite.hpp"
#include <vector>

class Bird : public Sprite {
public:
    Bird();
    ~Bird() override;

    void update();

private:
    std::vector<Texture*> flyFrames;

    int dy = 0; // vertical position modify for each frame

    int gravityForce = 1;
    void fall();

    int jumpForce = 3;
    float jumpTime = 0.0f;
    void jump();
};