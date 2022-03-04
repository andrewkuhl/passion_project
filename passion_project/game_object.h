//
//  game_object.hpp
//  passion_project
//
//  Created by Andrew Kuhl on 3/3/22.
//

#ifndef game_object_h
#define game_object_h

#include "game.h"

class Game_Object {
    
public:
    Game_Object(SDL_Renderer* render, const char* texture_sheet, int x, int y);
    ~Game_Object();
    
    void update();
    void render();
    
private:
    int xpos;
    int ypos;
    
    SDL_Texture* object_texture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
};

#endif /* game_object_hpp */
