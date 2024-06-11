#pragma once
#include <vector>
#include "block.hpp"

class Obstacle{
    public:
        Obstacle(Vector2 position);
        void Draw();
        Vector2 position;  
        std::vector<Block> blocks;
        std::vector<std::vector<int> grid; // obstacle is a 2D array(vector) overlapped on each one
    private:
}