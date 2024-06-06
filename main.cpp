#include <raylib.h>
#include "spaceship.hpp"

int main(){

    Color grey ={29,29,27,255};
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth,windowHeight, "C++ Space Invaders");
    SetTargetFPS(60); // speed of the game 

    // Spaceship Object Creation
    Spaceship spaceship;
    
    while(WindowShouldClose()== false){

        BeginDrawing();
        ClearBackground(grey);
        // draw new image for spaceships
        spaceship.Draw();
        EndDrawing();

    }

    CloseWindow();
}
