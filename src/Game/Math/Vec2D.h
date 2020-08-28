#pragma once
#include "Extern/glm/glm.hpp"

namespace PL_MATH
{
    
class Vec2D
{
public:
    float x;
    float y;
public:
    Vec2D();
    Vec2D(float xy);
    Vec2D(float x, float y);

    glm::vec2 GetGlmVec2() const;

    void Set(float x, float y);

    float Length() const;
    float SquaredLength() const;
    float Distance(Vec2D const& other) const;
    float SquaredDistance(Vec2D const& other) const;
    void Rotate(float radians);
    void Normalize();

    Vec2D operator - () const;
    Vec2D operator - (const Vec2D& rhs) const;
    void operator -= (const Vec2D& rhs);
    Vec2D operator + (float value) const;
    Vec2D operator + (const Vec2D& rhs) const;
    void operator += (const Vec2D& rhs);
    Vec2D operator * (float value) const;
    void operator *= (float value);
    Vec2D operator / (float value) const;
    
    static inline Vec2D Cross(Vec2D const& v, float a)
    {
        return Vec2D( a * v.y, -a * v.x );
    }

    static inline Vec2D Cross(float a, Vec2D const& v)
    {
        return Vec2D( -a * v.y, a * v.x );
    }

    static inline float Cross(Vec2D const& a, Vec2D const& b )
    {
        return a.x * b.y - a.y * b.x;
    }

    static inline float Dot(Vec2D const& a, Vec2D const& b )
    {
        return a.x * b.x + a.y * b.y;
    }
};

inline Vec2D operator * ( float value, Vec2D const& v )
{
  return Vec2D( value * v.x, value * v.y );
}

inline Vec2D operator / ( float value, Vec2D const& v )
{
  return Vec2D( value / v.x, value / v.y );
}
} // PL_MATH