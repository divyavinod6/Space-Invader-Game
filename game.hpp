#pragma once
#include "spaceship.hpp"
#include "obstacle.hpp"
#include "alien.hpp"
#include "mysteryship.hpp"
class Game {
public:
    Game();
    ~Game();
    void Draw();   // draw game objects
    void Update();  // update positions of game objects, called at every frame
    void HandleInput();  // handling player's input
    bool run; // false if game has stopped

private:
    Spaceship spaceship;
    std::vector<Obstacle> CreateObstacles();
    void DeleteInacticeLaser();
    std::vector<Obstacle> obstacles;
    std::vector<Alien> CreateAliens();
    void MoveAliens();  // invoke update method for alien class and give direction parameter
    void MoveDownAliens(int distance);
    void AlienShootLaser();// select alien at random and shoot laser
    std::vector<Alien> aliens; //  hold all vector
    int aliensDirection;
    std::vector<Laser> alienLasers;  // vector to store all alien laser
    constexpr static float alienLaserShootInterval = 0.35; // hold interval in ms to shoot laser
    float timeLastAlienFired; // hold time at which laser last fired
    MysteryShip mysteryship;
    float mysteryShipSpawnInterval;  // time at which mysteryship appears
    float timeLastSpawn; // time mysteryship was spawned
    void CheckForCollisions();  
    int lives; // spaceship has 3 lives before game over
    void GameOver();
    void Reset();
    void InitGame(); // initailise all variables to their initial values
};
