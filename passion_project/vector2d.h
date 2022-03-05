//
//  vector2d.h
//  passion_project
//
//  Created by Andrew Kuhl on 3/5/22.
//

#ifndef vector2d_h
#define vector2d_h


class Vector2D
{
public:
    
    float x;
    float y;
    
    Vector2D();
    Vector2D(float x, float y);
    
    Vector2D& add(const Vector2D& vec);
    Vector2D& sub(const Vector2D& vec);
    Vector2D& mul(const Vector2D& vec);
    Vector2D& div(const Vector2D& vec);
    
    //operator overloads for vector math v1 + v2
    friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);
    
    Vector2D& operator+=(const Vector2D& vec);
    Vector2D& operator-=(const Vector2D& vec);
    Vector2D& operator*=(const Vector2D& vec);
    Vector2D& operator/=(const Vector2D& vec);
};


#endif /* vector2d_h */
