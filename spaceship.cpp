#include "spaceship.hpp"

Spaceship::Spaceship()
{
    image = LoadTexture("Graphics/spaceship.png");
    position.x=(GetScreenWidth()-image.width )/2;
    position.y=GetScreenHeight()-image.height;
}

// destructer called automatically when game is closed
// To release image in memory after the game is closed

Spaceship::~Spaceship(){
    UnloadTexture(image);
}

void Spaceship::Draw(){
    DrawTextureV(image, position, WHITE);
}
void Spaceship::MoveLeft(){
    position.x -=7;
    // to prevent it from going outside boundary
    if(position.x < 0){
        position.x=0;
    }
}
void Spaceship::MoveRight(){
    position.x +=7;
    if(position.x > GetScreenWidth() - image.width){
        position.x= GetScreenWidth() - image.width;
    }
}