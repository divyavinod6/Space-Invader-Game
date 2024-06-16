#include "mysteryship.hpp"

MysteryShip::MysteryShip()
{
    image = LoadTexture("Graphics/mystery.png");
    alive=false;
}

MysteryShip::~MysteryShip()
{
    UnloadTexture(image);
}


void MysteryShip::Spawn(){
    // mysteryship image 90 pixels down from top screen
    position.y= 90;
    int side = GetRandomValue(0,1);  // mysteryship can move from left(0) or right(1)
    if(side==0){
        position.x = 25;
        speed=3;
    }
    else {
        position.x = GetScreenWidth()- image.width -25;
        speed=3;
    }
    alive = true; 
}

Rectangle MysteryShip::getRect()

{
    // only collid when musteryship is visible
    if(alive){
        return {position.x,position.y,float(image.width),float(image.height)};
    }
    else{
        return {position.x,position.y,0,0}; // if not alive send rectangle of size 0
    }
}

void MysteryShip::Update(){
    if(alive){
        position.x += speed;
        if(position.x >  GetScreenWidth() - image.width || position.x < 25){
            alive=false;
        }

    }
}

void MysteryShip::Draw()
{
    if(alive){
        DrawTextureV(image,position,WHITE);
    }
}

