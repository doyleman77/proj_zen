#include <iostream>
#include "game.hpp"

Game::Game()
{
    SDL_Init(SDL_INIT_VIDEO);
    window_title = "Project Zen v0.01";
    window_width = 640;
    window_height = 480;
    fps = 60;
    running = true;
    window = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, window_width,
                              window_height, 0);
    if(window == nullptr)
    {
        std::cout << "Error creating window " << SDL_GetError();
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr)
    {
        std::cout << "Error creating renderer " << SDL_GetError();
        return;
    }
}

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_Quit();
}

void Game::run()
{

    while(running == true)
    {
        // Input
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                running = false;
            if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_ESCAPE)
                    running = false;
            }
        }

        // Update

        // Draw
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    return;
}
