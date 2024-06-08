#pragma once
#include <raylib.h>

class Laser{
    public:
        Laser(Vector2 position, int speed);
        void Update();
        void Draw();

    private:
    Vector2 postion; 
    int speed; // how fast attribute moving on y axis
};