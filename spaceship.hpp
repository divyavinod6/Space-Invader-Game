#pragma once
#include <raylib.h>
#include "laser.hpp"
#include <vector>

class Spaceship {
public:
    Spaceship();
    ~Spaceship();

    void Draw();
    void MoveRight();
    void MoveLeft();
    void FireLaser();
    Rectangle getRect(); // enable collision
    std::vector<Laser> lasers;

private:
    Texture2D image;
    Vector2 position; // datatype representing position of spaceship (2D point/Vector with x and y components)
    double lastFireTime; // time in seconds from the laser last fired to keep lasers of equal length
};
