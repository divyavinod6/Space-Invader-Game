#pragma once
#include "spaceship.hpp"
#include "obstacle.hpp"
#include "alien.hpp"

class Game {
public:
    Game();
    ~Game();
    void Draw();   // draw game objects
    void Update();  // update positions of game objects
    void HandleInput();  // handling player's input

private:
    Spaceship spaceship;
    std::vector<Obstacle> CreateObstacles();
    void DeleteInacticeLaser();
    std::vector<Obstacle> obstacles;
    std::vector<Alien> CreateAliens();
    std::vector<Alien> aliens; //  hold all vector
};
