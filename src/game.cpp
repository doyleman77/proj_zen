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
    if(window == NULL)
    {
        std::cout << "Error creating window " << SDL_GetError();
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL)
    {
        std::cout << "Error creating renderer " << SDL_GetError();
    }
    ent = new Entity(renderer);
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
        if(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                running = false;

            if(event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                case SDLK_UP:
                    ent->move_up = true;
                    ent->y_vel = -1;
                    break;
                case SDLK_RIGHT:
                    ent->move_right = true;
                    ent->x_vel = 1;
                    break;
                case SDLK_DOWN:
                    ent->move_down = true;
                    ent->y_vel = 1;
                    break;
                case SDLK_LEFT:
                    ent->move_left = true;
                    ent->x_vel = -1;
                    break;
                case SDLK_ESCAPE:
                    running = false;
                    break;
                default:
                    break;
                }
            }
            else if(event.type == SDL_KEYUP)
            {
                switch(event.key.keysym.sym)
                {
                case SDLK_UP:
                    ent->move_up = false;
                    ent->y_vel = 0;
                    break;
                case SDLK_RIGHT:
                    ent->move_right = false;
                    ent->x_vel = 0;
                    break;
                case SDLK_DOWN:
                    ent->move_down = false;
                    ent->y_vel = 0;
                    break;
                case SDLK_LEFT:
                    ent->move_left = false;
                    ent->x_vel = 0;
                    break;
                default:
                    break;
                }
            }
        }

        // Update
        ent->update();
        // Draw
        SDL_RenderClear(renderer);
        ent->draw(renderer);

        SDL_SetRenderDrawColor(renderer, 175, 215, 125, 0);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    return;
}
