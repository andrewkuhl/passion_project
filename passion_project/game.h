//
//  game.hpp
//  passion_project
//
//  Created by Andrew Kuhl on 3/3/22.
//

#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

class Game
{
    
private:
    bool is_running;
    SDL_Window* window;
    int counter;
    
protected:
    
public:
    Game();
    ~Game();
    
    static SDL_Renderer* renderer;
    
    void init(const char* title, int xpos, int ypos, int width, int heigth,
              bool fullscreen);
    
    void handle_events();
    void update();
    void render();
    void clean();
    
    bool running();
    
    SDL_Texture* man_texture;
    static SDL_Event event;
};

#endif //__GAME_H__
