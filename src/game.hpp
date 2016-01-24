#pragma once

#include <string>
#include "SDL2/SDL.h"

class Game
{
public:
    /*ctr*/     Game();
    /*dtr*/     ~Game();
    void        run();
private:
    unsigned int short window_width;
    unsigned int short window_height;
    unsigned int short fps;
    bool running;
    std::string window_title;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
};
