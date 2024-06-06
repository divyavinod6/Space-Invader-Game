#pragma once
#include<raylib.h>
class Spaceship{
    public:
        Spaceship();
        ~Spaceship();

        void Draw();
        void MoveRight();
        void MoveLeft();
        void FireLaser();

    private:
        Texture2D image;
        Vector2 position; // datatype represeting position of spaceship (2D point/Vector with x and y components)

};