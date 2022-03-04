//
//  game_object.cpp
//  passion_project
//
//  Created by Andrew Kuhl on 3/3/22.
//

#include "game_object.h"
#include "texture_handler.h"

Game_Object::Game_Object(SDL_Renderer* render, const char* texture_sheet, int x, int y)
{
    renderer = render;
    object_texture =  Texture_Handler::load_texture(renderer, texture_sheet);
    
    xpos = x;
    ypos = y;
}
void Game_Object::update()
{
    
    xpos++;
    ypos++;
    
    srcRect.h = 64;
    srcRect.w = 64;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
    
}
void Game_Object::render()
{
    SDL_RenderCopy(renderer, object_texture, &srcRect, &destRect);
}
