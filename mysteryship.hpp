#pragma once
#include <raylib.h>

class MysteryShip{
    public:
        MysteryShip();
        ~MysteryShip();
        void Update();
        void Draw();
        void Spawn(); //  one spaceship that'll appear from time to time
        bool alive;   // true if spaceship visible on screen
        Rectangle getRect();
    private:
        Vector2 position;
        Texture2D image;
        int speed;

};