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

    int jumpForce = 4; // pair numbers
    float jumpTime = 0.0f;
    void jump();

    float animationTime = 0.0f;
    void flyAnimation();

    /**
     * bool solid:
     *          - Set on true, if you want solid corps
     *          - Set on false, if you want only return value
     */
    bool collisionWithBase(bool solid=true);
};