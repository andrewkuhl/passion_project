//
//  game.cpp
//  passion_project
//
//  Created by Andrew Kuhl on 3/3/22.
//

#include "game.h"
#include <iostream>

Game::Game()
{
    counter = 0;
}
Game::~Game()
{
    
}
void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flag = 0;
    if(fullscreen)
    {
        flag = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "sub systems initialized..." << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
        if(window)
        {
            std::cout<< "window created" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout<< "renderer created" << std::endl;
        }
        is_running = true;
    }
    else
    {
        is_running = false;
    }
}
void Game::handle_events()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch(event.type)
    {
        case SDL_QUIT:
            is_running = false;
            std::cout<< "closed" << std::endl;
            break;
            
        default:
            break;
    }
}
void Game::update()
{
    std::cout<< counter << std::endl;
    counter++;
}
void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<< "cleaned" << std::endl;
}
bool Game::running()
{
    return is_running;
}
