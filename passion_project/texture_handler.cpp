//
//  texture_handler.cpp
//  passion_project
//
//  Created by Andrew Kuhl on 3/3/22.
//

#include "texture_handler.h"

SDL_Texture* Texture_Handler::load_texture(SDL_Renderer* render, const char* texture)
{
    return IMG_LoadTexture(render, texture);
}
