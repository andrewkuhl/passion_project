//
//  game.cpp
//  passion_project
//
//  Created by Andrew Kuhl on 3/3/22.
//

#include "game.h"
#include "texture_handler.h"
#include "ecs/components.h"
#include "vector2d.h"

#include <iostream>

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& player(manager.add_entity());


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
    
    player.add_component<TransformComponent>();
    player.add_component<SpriteComponent>("/Users/andrewkuhl/passion_project/assets/man.png");
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
    manager.refresh();
    manager.update();
    player.get_component<TransformComponent>().position.add(Vector2D(1,2));
    
}
void Game::render()
{
    SDL_RenderClear(renderer);
    manager.draw();
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
