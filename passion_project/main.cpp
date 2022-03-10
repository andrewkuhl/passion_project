//
//  main.cpp
//  passion_project
//
//  Created by Andrew Kuhl on 3/3/22.
//
#include "game.h"


int main(int argc, const char * argv[])
{
    
    const int fps = 60;
    const int frame_delay = 1000 / fps; //max time between frames
    
    //game time huge integer
    Uint32 frame_start;
    int frame_time;
    
    //create game object
    Game *game = new Game();
    
    //run init
    game->init("game_engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 840, false);
    //while game is running
    while(game->running())
    {
        
        frame_start = SDL_GetTicks();
        
        //handle inputs
        game->handle_events();
        //update game
        game->update();
        //render updates
        game->render();
        
        frame_time = SDL_GetTicks() - frame_start; //how many frames encounter took
        
        if(frame_delay > frame_time)
        {
            SDL_Delay(frame_delay - frame_time); //if its going too fast delay the frame
        }
    }
    return 1;
}
