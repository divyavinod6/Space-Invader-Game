#include "game.hpp"
#include <iostream>

Game::Game() {
    // Initialize spaceship or other game objects here
}

Game::~Game() {
    // Cleanup if needed
}

void Game::Draw() {
    spaceship.Draw();
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
    std::cout<< "Vector Size" << spaceship.lasers.size() << std::endl;
    
}
