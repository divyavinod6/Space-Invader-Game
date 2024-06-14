#include "laser.hpp"

Laser::Laser(Vector2 position, int speed) : position(position), speed(speed), active(true) {}

void Laser::Draw() {
    if (active) {
        DrawRectangle(position.x, position.y, 4, 15, {243, 216, 63, 255}); // render fixed rectangle on the screen. Dimensions 4x15 pixels
    }
}

void Laser::Update() {
    // as laser only moves on the y axis so only alter y position of rectangle at every frame
    position.y += speed;
    if (active) {
        if (position.y > GetScreenHeight() || position.y < 0) {
            active = false;
        }
    }
}

Rectangle Laser::getRect(){
    Rectangle rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.width = 4;
    rect.height = 15;
    return rect;
}