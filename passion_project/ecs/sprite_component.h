//
//  sprite_component.h
//  passion_project
//
//  Created by Andrew Kuhl on 3/4/22.
//

#ifndef sprite_component_h
#define sprite_component_h

#include "components.h"
#include <SDL2/SDL.h>
#include <iostream>

class SpriteComponent : public Component
{
private:
    TransformComponent* transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
    const char* path;
    
public:
    SpriteComponent() = default;
    
    SpriteComponent(const char* set_path)
    {
        set_texture(set_path);
        if(texture)
        {
            std::cout << "loaded sprite: " << set_path << std::endl;
        }
        path = set_path;
    }
    
    void set_texture(const char* path)
    {
        texture = Texture_Handler::load_texture(path);
    }
    
    void init() override
    {
        
        transform = &entity->get_component<TransformComponent>();
        
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 64;
        destRect.x = destRect.y = 0;
        destRect.w = destRect.h = 128;
    }
    void update() override
    {
        destRect.x = (int)transform->position.x;
        destRect.y = (int)transform->position.y;
        switch(transform->facing)
        {
            case TransformComponent::NORTH:
                set_texture("/Users/andrewkuhl/passion_project/assets/man_n.png");
                break;
            case TransformComponent::SOUTH:
                set_texture("/Users/andrewkuhl/passion_project/assets/man_s.png");
                break;
            case TransformComponent::EAST:
                set_texture("/Users/andrewkuhl/passion_project/assets/man_e.png");
                break;
            case TransformComponent::WEST:
                set_texture("/Users/andrewkuhl/passion_project/assets/man_w.png");
                break;
            case TransformComponent::NORTH_WEST:
                set_texture("/Users/andrewkuhl/passion_project/assets/man_nw.png");
                break;
            case TransformComponent::SOUTH_WEST:
                set_texture("/Users/andrewkuhl/passion_project/assets/man_sw.png");
                break;
            case TransformComponent::NORTH_EAST:
                set_texture("/Users/andrewkuhl/passion_project/assets/man_ne.png");
                break;
            case TransformComponent::SOUTH_EAST:
                set_texture("/Users/andrewkuhl/passion_project/assets/man_se.png");
                break;
        }
    }
    void draw() override
    {
        Texture_Handler::draw(texture, srcRect, destRect);
    }
    
};

#endif /* sprite_component_h */
