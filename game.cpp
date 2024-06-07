#include "game.hpp"

Game::Game()
{
}
Game::~Game()
{
}

void Game::Draw(){
    spaceship.Draw();
}

void Game::HandleInput(){
    // check if user has pressed left key
    if(IsKeyDown(KEY_LEFT)){
        spaceship.MoveLeft();
    }
    else if(IsKeyDown(KEY_RIGHT)){
        spaceship.MoveRight();
    }
}