#include <raylib.h>
#include "game.hpp"

int main(){

    Color grey ={29,29,27,255};
    Color yellow = {243,216,63,255};
    int offset = 50;  // for interface 800x800 
    int windowWidth = 735;
    int windowHeight = 730;

    InitWindow(windowWidth + offset,windowHeight + offset, "C++ Space Invaders");
    SetTargetFPS(60); // speed of the game 

    // Spaceship Object Creation

    // Game Object Creation
    Game game;
    Obstacle obstacle=Obstacle({100,100});

     
    while(WindowShouldClose()== false){

        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(grey);
        DrawRectangleRoundedLines({10,10,760,760}, 0.18f,20,2,yellow); // rectangular frame
        DrawLineEx({16,730},{766,730},3, yellow); // draw horizontal line on screen
        // draw new image for spaceships
        game.Draw();
    
        EndDrawing();

    }

    CloseWindow();
}
