#pragma once
#include "spaceship.hpp"
class Game{
    public:
        Game();
        ~Game();
        void Draw();   // draw game objects
        void Update();  // update positions of game objects
        void HandleInput();  //  handling players input
    private:
        Spaceship spaceship;
};