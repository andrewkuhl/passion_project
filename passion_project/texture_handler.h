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
    
    static SDL_Texture* load_texture(const char* texture);
    
    static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
    
};

#endif /* texture_handler_hpp */
