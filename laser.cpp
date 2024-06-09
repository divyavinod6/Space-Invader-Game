#include "laser.hpp"
#include <iostream>

Laser::Laser(Vector2 position, int speed)
{
    this-> position=position;
    this-> speed= speed;
}

void Laser::Draw(){
    if(active)
    DrawRectangle(position.x, position.y, 4,15, {243,216,63,255}); // render fixed rectangle on the screen. Dimensions 4x15 pixels
} 

void Laser::Update(){
    // as laser only moves on the y axis so only alter y position of rectangle at every frame
    position.y += speed;
    if(active){
        if(position.y > GetScreenHeight() || position.y <0){
            active=false;
        }
    }
}