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
    std::vector<Laser> lasers;

private:
    Texture2D image;
    Vector2 position; // datatype representing position of spaceship (2D point/Vector with x and y components)
};
