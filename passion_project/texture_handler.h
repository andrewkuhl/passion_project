//
//  texture_handler.hpp
//  passion_project
//
//  Created by Andrew Kuhl on 3/3/22.
//

#ifndef texture_handler_h
#define texture_handler_h

#include "game.h"

class Texture_Handler
{
    
    public:
    static SDL_Texture* load_texture(SDL_Renderer* render, const char* texture);
    
};

#endif /* texture_handler_hpp */
