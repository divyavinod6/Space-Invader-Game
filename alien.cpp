#include "alien.hpp"

Texture2D Alien::alienImages[3]={};


Alien::Alien(int type, Vector2 position)
{
    this->type= type;
    this->position = position;

    if(alienImages[type-1].id==0){
        // if true, alienImages not initialised
        //load images from disk
        switch ((type)){
            case 1:
                alienImages[0] = LoadTexture("Graphics/alien_1.png");
                break;
            case 2:
                alienImages[1]= LoadTexture("Graphics/alien_2.png");
                break;
            case 3:
                alienImages[2]= LoadTexture("Graphics/alien_3.png");
                break;
            default:
                alienImages[0]=LoadTexture("Graphics/alien_1.png");
                break;
        }
    }

}

void Alien::Update(int direction)
{
    // move x attribute of each alien
    position.x +=direction;
    

}

void Alien::Draw(){
    DrawTextureV(alienImages[type-1], position,WHITE); // draw image on position on screen
}

int Alien::GetType(){
    return type;
}

void Alien::UnloadImages()
{
    for(int i=0;i<4;i++){
        UnloadTexture(alienImages[i]);
    }
}
