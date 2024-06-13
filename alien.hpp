#pragma once
#include <raylib.h>

class Alien{
    public:
        Alien(int type,Vector2 position);
        void Update(int direction); //  direction to control movement of aliens
        void Draw();
        int GetType();  // return type of alien
        static void UnloadImages(); // when game window is closed 
        static Texture2D alienImages[3];  // common attribute containing all 3 images, loaded after Alien object is created
        int type;  // for 2 types of aliens 
        Vector2 position;

    private:
};