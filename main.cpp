#include <raylib.h>
#include "game.hpp"
#include <string>

// convert number in string with leading 0
std::string FormatWithLeadingZeros(int number, int width){
    std::string numberText = std::to_string(number);
    int leadingZeros = width - numberText.length();
    return numberText = std::string(leadingZeros, '0') + numberText;
    
}


int main(){

    Color grey ={29,29,27,255};
    Color yellow = {243,216,63,255};
    int offset = 50;  // for interface 800x800 
    int windowWidth = 735;
    int windowHeight = 730;

    InitWindow(windowWidth + offset,windowHeight + offset, "C++ Space Invaders");
    SetTargetFPS(60); // speed of the game 

    
    Font font = LoadFontEx("Font/monogram.ttf",64,0,0);  // font loaded in memory
    Texture2D spaceshipImage = LoadTexture("Graphics/spaceship.png");
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
        if(game.run){
            DrawTextEx(font, "LEVEL 01", {570,730},34,2,yellow);
        }else{
            DrawTextEx(font, "GAME OVER", {570,730},34 ,2, yellow);        
        }
        // Display lives left
        float x=50.0;
        for(int i=0;i< game.lives;i++){
            DrawTextureV(spaceshipImage,{x,745}, WHITE);  // x represents position in x azis
            x+=50;
        }

        // Display score text
        DrawTextEx(font, "SCORE",{50,15}, 34,2, yellow);
        std::string scoreText = FormatWithLeadingZeros(game.score, 5);
        DrawTextEx(font, scoreText.c_str(), {50,40}, 34,2,yellow);

        // Display highscore
        DrawTextEx(font, "HIGH SCORE", {570,15}, 34,2, yellow);
        std::string highscoreText = FormatWithLeadingZeros(game.highscore,5);
        DrawTextEx(font, highscoreText.c_str(), {655,40},34,2,yellow);
        // draw new image for spaceships
        game.Draw();
    
        EndDrawing();

    }

    CloseWindow();
}
