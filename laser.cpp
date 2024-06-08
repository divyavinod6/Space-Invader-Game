#include "laser.hpp"

Laser::Laser(Vector2 position, int speed)
{
    this -> postion= position;
    this-> speed= speed;
}

void Laser::Draw(){
    DrawRectangle(postion.x, postion.y, 4,15, {243,216,63,255}); // render fixed rectangle on the screen. Dimensions 4x15 pixels
}