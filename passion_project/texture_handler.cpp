//
//  texture_handler.cpp
//  passion_project
//
//  Created by Andrew Kuhl on 3/3/22.
//

#include "texture_handler.h"

SDL_Texture* Texture_Handler::load_texture(const char* texture)
{
    return IMG_LoadTexture(Game::renderer, texture);
}
void Texture_Handler::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
