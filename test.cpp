#include <raylib.h>

int main(){
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth,windowHeight, "C++ Space Invaders");


    SetTargetFPS(60); // speed of the game 
    
    while(WindowShouldClose()== false){

        BeginDrawing();
        EndDrawing();

    }

    CloseWindow();
}
