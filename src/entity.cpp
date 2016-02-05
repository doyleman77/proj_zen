#include "entity.hpp"

#include <iostream>

Entity::Entity(SDL_Renderer* renderer)
{
    x = y = x_vel = y_vel = 0;
    sprite.x = sprite.y = sprite.w = sprite.h = 0;

    SDL_Surface* temp_surface = SDL_LoadBMP("test.bmp");
    if(temp_surface == NULL)
    {
        std::cout << "Error loading .bmp! " << SDL_GetError() << std::endl;
    }

    SDL_SetColorKey(temp_surface, SDL_TRUE, SDL_MapRGB(temp_surface->format, 0xFF, 0, 0xFF));

    image = SDL_CreateTextureFromSurface(renderer, temp_surface);
    SDL_FreeSurface(temp_surface);
    if(image == NULL)
    {
        std::cout << "Eror converting .bmp to texture! " << SDL_GetError() << std::endl;
    }
    SDL_QueryTexture(image, NULL, NULL, &sprite.w, &sprite.h);
}


Entity::~Entity()
{
    SDL_DestroyTexture(image);
}

void Entity::move(int temp_x, int temp_y)
{
    x = temp_x;
    y = temp_y;
}

void Entity::draw(SDL_Renderer* renderer)
{
    SDL_Rect temp = sprite;
    temp.x = x;
    temp.y = y;
    SDL_RenderCopy(renderer, image, &sprite, &temp);

}

void Entity::update()
{
    if(move_up) move(x, y+y_vel);
    if(move_right) move(x+x_vel, y);
    if(move_down) move(x, y+y_vel);
    if(move_left) move(x+x_vel, y);
}
