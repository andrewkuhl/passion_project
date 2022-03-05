//
//  vector2d.cpp
//  passion_project
//
//  Created by Andrew Kuhl on 3/5/22.
//

#include "vector2d.h"
#include <iostream>

Vector2D::Vector2D()
{
    x = 0.0f;
    y = 0.0f;
}
Vector2D::Vector2D(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector2D& Vector2D::add(const Vector2D& vec)
{
    this->x += vec.x;
    this->y += vec.y;
    
    return *this;
}
Vector2D& Vector2D::sub(const Vector2D& vec)
{
    this->x -= vec.x;
    this->y -= vec.y;
    
    return *this;
}
Vector2D& Vector2D::mul(const Vector2D& vec)
{
    this->x *= vec.x;
    this->y *= vec.y;
    
    return *this;
}
Vector2D& Vector2D::div(const Vector2D& vec)
{
    this->x /= vec.x;
    this->y /= vec.y;
    
    return *this;
}


//operator overloads for vector math v1 + v2
Vector2D& operator+(Vector2D& v1, const Vector2D& v2)
{
    return v1.add(v2);
}
Vector2D& operator-(Vector2D& v1, const Vector2D& v2)
{
    return v1.sub(v2);
}
Vector2D& operator*(Vector2D& v1, const Vector2D& v2)
{
    return v1.mul(v2);
}
Vector2D& operator/(Vector2D& v1, const Vector2D& v2)
{
    return v1.div(v2);
}

Vector2D& Vector2D::operator+=(const Vector2D& vec)
{
    return this->add(vec);
    
}
Vector2D& Vector2D::operator-=(const Vector2D& vec)
{
    return this->sub(vec);
}
Vector2D& Vector2D::operator*=(const Vector2D& vec)
{
    return this->mul(vec);
}
Vector2D& Vector2D::operator/=(const Vector2D& vec)
{
    return this->div(vec);
}
