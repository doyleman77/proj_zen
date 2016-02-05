#pragma once

#include "SDL2/SDL.h"

class Entity
{
public:
    /*ctr*/     Entity(SDL_Renderer*);
    /*dtr*/     ~Entity();
    void move(int x, int y);
    void draw(SDL_Renderer*);
    void update();

private:
    unsigned int x, y;
    SDL_Rect sprite;
    SDL_Texture* image;
};
