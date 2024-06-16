#include "game.hpp"
#include <iostream>
#include <fstream>

Game::Game() {
    InitGame();
}

Game::~Game() {
    // Cleanup if needed
    Alien::UnloadImages();
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

    // draw all aliens
    for(auto& alien:aliens){
        alien.Draw();
    }

    // draw all alien lasers
    for(auto& laser:alienLasers){
        laser.Draw();
    } 

    // draw mysteryship that comes at random
    mysteryship.Draw();


}

void Game::HandleInput() {
    if(run){
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
    // // remove inactive laser shot from aliens
    for(auto it = alienLasers.begin(); it!= alienLasers.end();){
        if(!it->active){
            it = alienLasers.erase(it);
        }
        else{
            ++it;
        }
    }
}

std::vector<Alien> Game::CreateAliens()
{
    std::vector<Alien> alien;  // 5 rows 11 column of alien, so creating a grid
    for(int row=0;row<5;row++){
        for(int column=0;column<11;column++){
            int alienType;
            if(row==0){
                alienType=3;
            }else if(row==1 || row==2){
                alienType=2;
            }else{
                alienType=1;
            }

            float x=75+column*55; // cellSize hardcoded to 55, offset of 75
            float y=110+ row*55;  //  offset of 110
            aliens.push_back(Alien(alienType, {x,y}));  //  
        }
    }
    return aliens;
}

void Game::MoveAliens()
{
    for(auto& alien:aliens){
        if(alien.position.x + alien.alienImages[alien.type -1].width > GetScreenWidth() -25){
            aliensDirection=-1;
            MoveDownAliens(4);
        }
        if(alien.position.x < 25){
            aliensDirection=1;
            MoveDownAliens(4);
        }
        alien.Update(aliensDirection);
    }
} 

void Game::MoveDownAliens(int distance)
{
    for(auto& alien:aliens){
        alien.position.y += distance;
    }
}

void Game::AlienShootLaser()
{
    double currentTime = GetTime();
    // keeping interval for alien laser as 350ms
    
    if(currentTime - timeLastAlienFired >= alienLaserShootInterval && !aliens.empty()){
        int randomIndex = GetRandomValue(0,aliens.size()-1);
        Alien& alien = aliens[randomIndex];// random alien object
        alienLasers.push_back(Laser({alien.position.x + alien.alienImages[alien.type -1].width/2,
                                    alien.position.y + alien.alienImages[alien.type-1].height},6)); // laser for random alien , position is center and bottom of alien image on x and y axis, speed 6
        timeLastAlienFired = GetTime();

    }
}

void Game::CheckForCollisions()
{
    // Spaceship Laser

    // loop through alien vector to check if they have collided with laser
    for(auto& laser:spaceship.lasers){
        auto it = aliens.begin();  // points to begin of iterator
        while(it != aliens.end()){
            if(CheckCollisionRecs(it -> getRect(), laser.getRect())){
                // collision happened

                if (it->type == 1){
                    score +=100;
                }
                else if(it-> type == 2){
                    score += 200;
                }
                else if(it -> type ==3){
                    score +=300;
                }
                CheckForHighScore();
                it = aliens.erase(it); // removes alien and points to next 
                laser.active = false;
            }
            else{
                // no collision with current alien, move to next
                ++it;
            }
        }

        // loop through 4 obstacles to check collision with spaceship laser
        for(auto& obstacle: obstacles){
            auto it = obstacle.blocks.begin();
            while(it != obstacle.blocks.end()){
                if(CheckCollisionRecs(it -> getRect(), laser.getRect())){
                    // remove block from vector and make laser inactive
                    it = obstacle.blocks.erase(it);
                    laser.active = false;
                }
                else{
                    ++it;
                }
            }
        }

         // check collisions with mystery ship
         if(CheckCollisionRecs(mysteryship.getRect(), laser.getRect())){
            mysteryship.alive =false;
            laser.active = false;
            score += 500;
            CheckForHighScore();
         }

    }

    // Alien Lasers

    for(auto& laser:alienLasers){
        if(CheckCollisionRecs(laser.getRect(),spaceship.getRect())){
            // deactivate laser and print on console to indicate life lost
            laser.active = false;
            lives--;
            std::cout<< "Spaceship Hit!!" <<std::endl;
            if(lives==0){
                GameOver();
            }
        }

        // loop through 4 obstacles to check collision with alien  laser
        for(auto& obstacle: obstacles){
            auto it = obstacle.blocks.begin();
            while(it != obstacle.blocks.end()){
                if(CheckCollisionRecs(it -> getRect(), laser.getRect())){
                    // remove block from vector and make laser inactive
                    it = obstacle.blocks.erase(it);
                    laser.active = false;
                }
                else{
                    ++it;
                }
            }
        }
    }
    // Alien collision with obstacle
    for(auto& alien:aliens){
        for(auto& obstacle: obstacles){
            auto it=  obstacle.blocks.begin();
            while(it != obstacle.blocks.end()){
                if(CheckCollisionRecs(it-> getRect(), alien.getRect())){
                    it = obstacle.blocks.erase(it);
                }else{
                    it++;
                }
            }
        }

        // if alien collides with spaceship
        if(CheckCollisionRecs(alien.getRect(), spaceship.getRect())){
            // std::cout << "Spaceship hit by Alien" <<std::endl;
            GameOver();
        }
    }

}

void Game::GameOver()
{
    std::cout<<"Game Over" <<std::endl;
    std::cout<<"Press Enter To Restart" <<std::endl;
    run=false;
}

void Game::InitGame()
{
    // Initialize spaceship or other game objects here
    obstacles = CreateObstacles();  // holds 4 obstacle objects
    aliens= CreateAliens();
    aliensDirection=1;
    timeLastAlienFired = 0.0;
    timeLastSpawn  = 0.0;
    mysteryShipSpawnInterval = GetRandomValue(10,20);
    lives = 3;
    score = 0;
    highscore = loadHighscoreFromFile();
    run=true;
}

void Game::CheckForHighScore()
{
    if(score >  highscore){
        highscore = score;
        SaveHighscoreToFile(highscore);
    }
}

void Game::SaveHighscoreToFile(int highscore)
{
    std::ofstream highscoreFile("highscore.txt");
    // if file open write current highscore file
    if(highscoreFile.is_open()){
        highscoreFile << highscore;
        highscoreFile.close();
    }
    else{
        std::cerr << "Failed to save highscore to file" << std::endl;
    }
}

int Game::loadHighscoreFromFile()
{
    int loadedHighscore =0;
    std::ifstream highscoreFile("highscore.txt"); // initalises an input file stream object to reads from highscore.txt
    if(highscoreFile.is_open()){
        highscoreFile >> loadedHighscore;
        highscoreFile.close();
    }else{
        std::cerr <<"Failed to load highscore from file"<<std::endl;
    }
    return loadedHighscore;
}

void Game::Reset(){
    spaceship.Reset(); // move spaceship sprite to center of screen
    aliens.clear();  // delete all aliens from alien vector
    alienLasers.clear(); // delete all lasers
    obstacles.clear(); // clear obstacles from its vector
    
}

void Game::Update() {
    // check if game not over and only update positions if game runs
    if(run){
        // check if mysteryship event has occured
        // call spawn method if interval has passed
        double currentTime = GetTime();
        if(currentTime -  timeLastSpawn > mysteryShipSpawnInterval){
            mysteryship.Spawn();
            timeLastSpawn = GetTime();
            mysteryShipSpawnInterval = GetRandomValue(10,20);
        }


        for (auto& laser : spaceship.lasers) {
            laser.Update();
        }
        MoveAliens();
        AlienShootLaser(); //  created alien laser
        // to move alien laser
        for(auto& laser:alienLasers){
            laser.Update();
        }
        DeleteInacticeLaser(); 
        mysteryship.Update();
        CheckForCollisions();
    }
    else{
        // game over, choice of game restart
        if(IsKeyDown(KEY_ENTER)){
            Reset();
            InitGame();
        }

    }
}

std::vector<Obstacle> Game::CreateObstacles(){
    int obstacleWidth= Obstacle::grid[0].size()*3;
    // to ensure equal gap between all 4 obstacles 
    float gap=(GetScreenWidth()- (4*obstacleWidth))/5;
    for(int i=0;i<4;i++){
        float offsetX = (i+1)*gap +(i*obstacleWidth); // calculates horizontal gap between each obstacle being evenly spaced
        obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight()-200)}));   // creat obstacles and insert them into obstacles vector
    }
    return obstacles;
}