#pragma once
#include <raylib.h>
#include <vector>
#include "block.hpp"

class Obstacle {
public:
    Obstacle(Vector2 position);
    void Draw();
    Vector2 position;
    std::vector<Block> blocks;
    static std::vector<std::vector<int>> grid; // 2D array (vector) for the obstacle shape

private:
};
