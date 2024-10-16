#pragma once
#include "../graphics/sprite.hpp"

/** 
 * There are two bases in the game 
 *
 * FIRST: that's the base that will visualize on screen before.
 * LAST: that's the base that will visualize on screen after that the first base go out the screen.
*/
enum BaseOrder {
    FIRST, LAST
};

class Base : public Sprite {
public:
    Base(BaseOrder baseOrder);
    ~Base() override;

    void update();

private:
    BaseOrder baseOrder;

    int dx = 0;
    int speed = -1;
    void move();
};