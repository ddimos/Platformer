#pragma once
#include "Vec2D.h"

namespace PL_MATH
{

struct Mat2D
{
    union
    {
        struct
        {
            float m00, m01;
            float m10, m11;
        };

        float m[2][2];
        float v[4];
    };
    

    Mat2D();
    Mat2D(float radians);
    Mat2D(float m00, float m01, float m10, float m11);

    void Set(float radians);

    Mat2D Abs() const;

    Vec2D AxisX() const;
    Vec2D AxisY() const;

    Mat2D Transpose() const;
    Vec2D const operator*(Vec2D const& rhs ) const;
    Mat2D const operator*(Mat2D const& rhs ) const;  
};
        
} // PL_MATH