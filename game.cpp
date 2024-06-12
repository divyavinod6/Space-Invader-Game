#include "game.hpp"
#include <iostream>

Game::Game() {
    // Initialize spaceship or other game objects here
    obstacles = CreateObstacles();  // holds 4 obstacle objects
}

Game::~Game() {
    // Cleanup if needed
}

void Game::Draw() {
    spaceship.Draw();

    for(auto& laser:spaceship.lasers){
        laser.Draw();
    }

    // draw obstacles
    for(auto& obstacle:obstacles){
        obstacle.Draw();
    }


}

void Game::HandleInput() {
    if (IsKeyDown(KEY_RIGHT)) {
        spaceship.MoveRight();
    }
    if (IsKeyDown(KEY_LEFT)) {
        spaceship.MoveLeft();
    }
    if (IsKeyPressed(KEY_SPACE)) {
        spaceship.FireLaser();
    }
}

void Game::DeleteInacticeLaser()
{
    // check if any laser inactive if yes remove from vector
    for(auto it = spaceship.lasers.begin(); it!= spaceship.lasers.end();){
        if(!it->active){
            it = spaceship.lasers.erase(it);
        }
        else{
            ++it;
        }
    }
}

void Game::Update() {
    for (auto& laser : spaceship.lasers) {
        laser.Update();
    }
    DeleteInacticeLaser(); 
    
}

std::vector<Obstacle> Game::CreateObstacles(){
    int obstacleWidth= Obstacle::grid[0].size()*3;
    // to ensure equal gap between all 4 obstacles 
    float gap=(GetScreenWidth()- (4*obstacleWidth))/5;
    for(int i=0;i<4;i++){
        float offsetX = (i+1)*gap +(i*obstacleWidth); // calculates horizontal gap between each obstacle being evenly spaced
        obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight()-100)}));   // creat obstacles and insert them into obstacles vector
    }
    return obstacles;
}