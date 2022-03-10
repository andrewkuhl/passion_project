//
//  keyboard_component.h
//  passion_project
//
//  Created by Andrew Kuhl on 3/5/22.
//

#ifndef keyboard_component_h
#define keyboard_component_h

#include "../game.h"
#include "ecs.h"
#include "components.h"

class KeyboardComponent : public Component
{
public:
    TransformComponent* transform;
    
    void init() override
    {
        transform = &entity->get_component<TransformComponent>();
    }
    
    void update() override
    {
        if(Game::event.type == SDL_KEYDOWN)
        {
            //set velocity for key press
            switch(Game::event.key.keysym.sym)
            {
                case SDLK_w:
                    transform->velocity.y = -1;
                    break;
                case SDLK_a:
                    transform->velocity.x = -1;
                    break;
                case SDLK_s:
                    transform->velocity.y = 1;
                    break;
                case SDLK_d:
                    transform->velocity.x = 1;
                    break;
                default:
                    break;
            }
        }
        if(Game::event.type == SDL_KEYUP)
        {
            //reset velocity
            switch(Game::event.key.keysym.sym)
            {
                case SDLK_w:
                    transform->velocity.y = 0;
                    break;
                case SDLK_a:
                    transform->velocity.x = 0;
                    break;
                case SDLK_s:
                    transform->velocity.y = 0;
                    break;
                case SDLK_d:
                    transform->velocity.x = 0;
                    break;
                default:
                    break;
            }
        }
        
    }
};


#endif /* keyboard_component_h */
