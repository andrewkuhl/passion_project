//
//  main.cpp
//  passion_project
//
//  Created by Andrew Kuhl on 3/3/22.
//
#include "game.h"


int main(int argc, const char * argv[]) {
    
    //create game object
    Game *game = new Game();
    
    game->init("game_engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    //while game is running
    while(game->running())
    {
        //handle inputs
        game->handle_events();
        //update game
        game->update();
        //render updates
        game->render();
    }
    return 1;
}
