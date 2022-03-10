//
//  transform_component.h
//  passion_project
//
//  Created by Andrew Kuhl on 3/4/22.
//

#ifndef transform_component_h
#define transform_component_h

#include "components.h"
#include "../vector2d.h"
#include <iostream>

class TransformComponent : public Component
{
public:
    
    Vector2D position;
    Vector2D velocity;
    
    typedef enum {
        NORTH, SOUTH, EAST, WEST, NORTH_WEST, SOUTH_WEST, SOUTH_EAST, NORTH_EAST
    } Direction;
    
    Direction facing;
    
    int speed = 4;
    
    
    TransformComponent()
    {
        position.x = 0.0f;
        position.y = 0.0f;
        
    }
    TransformComponent(float x, float y)
    {
        position.x = x;
        position.y = y;
    }
    
    void init() override
    {
        velocity.x = 0;
        velocity.y = 0;
        
        facing = SOUTH;
    }
    void update() override
    {
        position.x += velocity.x*speed;
        position.y += velocity.y*speed;
        
        
        if(velocity.x*speed == 0 && velocity.y*speed < 0)
        {
            //north
            facing = NORTH;
        }
        else if(velocity.x*speed < 0 && velocity.y*speed < 0)
        {
            //north west
            facing = NORTH_WEST;
        }
        else if(velocity.x*speed < 0 && velocity.y*speed == 0)
        {
            //west
            facing = WEST;
        }
        else if(velocity.x*speed < 0 && velocity.y*speed > 0)
        {
            //south west
            facing = SOUTH_WEST;
        }
        else if(velocity.x*speed == 0 && velocity.y*speed > 0)
        {
            //south
            facing = SOUTH;
        }
        else if(velocity.x*speed > 0 && velocity.y*speed > 0)
        {
            //south east
            facing = SOUTH_EAST;
        }
        else if(velocity.x*speed > 0 && velocity.y*speed == 0)
        {
            //east
            facing = EAST;
        }
        else if(velocity.x*speed > 0 && velocity.y*speed < 0)
        {
            //north east
            facing = NORTH_EAST;
        }
        else{
            
        }
    }
        
};
#endif /* transform_component_h */
