#pragma once
#include <raylib.h>

class Laser {
public:
    Laser(Vector2 position, int speed);
    void Update();
    void Draw();
    bool active;
    Vector2 position; // make position public
    Rectangle getRect();

private:
    int speed; // how fast attribute moving on y axis
};
