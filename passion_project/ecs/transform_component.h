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


class TransformComponent : public Component
{
public:
    
    Vector2D position;
    
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
    
    void update() override
    {
        
    }
    
};
#endif /* transform_component_h */
