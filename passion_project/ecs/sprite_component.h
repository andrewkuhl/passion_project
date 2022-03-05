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
    PositionComponent* position;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
    
public:
    SpriteComponent() = default;
    
    SpriteComponent(const char* path)
    {
        texture = Texture_Handler::load_texture(path);
        if(texture)
        {
            std::cout << "loaded sprite: " << path << std::endl;
        }
    }
    
    void init() override
    {
        position = &entity->get_component<PositionComponent>();
        
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 64;
        destRect.w = destRect.h = 64;
    }
    void update() override
    {
        destRect.x = position->x();
        destRect.y = position->y();
    }
    void draw() override
    {
        Texture_Handler::draw(texture, srcRect, destRect);
    }
    
};

#endif /* sprite_component_h */
