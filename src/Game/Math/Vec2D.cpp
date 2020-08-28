#include "Vec2D.h"
#include "Game/Math/Utils.h"

namespace PL_MATH
{

Vec2D::Vec2D()
  :
  x(0.0f)
  ,y(0.0f)
{
}

Vec2D::Vec2D(float xy)
  :
  x(xy)
  ,y(xy)
{
    
}

Vec2D::Vec2D(float x, float y)
  :
  x(x)
  ,y(y)
{
}

glm::vec2 Vec2D::GetGlmVec2() const
{
  return glm::vec2(x, y);
}

void Vec2D::Set(float x, float y)
{
  this->x = x;
  this->y = y;
}

float Vec2D::Length() const
{
  return Sqrt(SquaredLength());
}

float Vec2D::SquaredLength() const
{
  return x*x + y*y;
}

float Vec2D::Distance(Vec2D const& other) const
{
  return Sqrt(SquaredDistance(other));
}

float Vec2D::SquaredDistance(Vec2D const& other) const
{
  float const x = other.x - x;
  float const y = other.y - y;
  return x*x + y*y;
}

void Vec2D::Rotate(float radians)
{
  float const c = std::cos( radians );
  float const s = std::sin( radians );

  float const xp = x * c - y * s;
  float const yp = x * s + y * c;

  x = xp;
  y = yp;
}

void Vec2D::Normalize()
{
  float const len = Length();

  if(len > EPSILON)
  {
    float invLen = 1.0f / len;
    x *= invLen;
    y *= invLen;
  }
}

Vec2D Vec2D::operator - () const
{
  return Vec2D(-x, -y);
}

Vec2D Vec2D::operator - (const Vec2D& rhs) const
{
  return Vec2D(x - rhs.x, y - rhs.y);
}

void Vec2D::operator -= (const Vec2D& rhs)
{
  x -= rhs.x;
  y -= rhs.y;
}

Vec2D Vec2D::operator + (float value) const
{
  return Vec2D(x + value, y + value);
}

Vec2D Vec2D::operator + (const Vec2D& rhs) const
{
  return Vec2D(x + rhs.x, y + rhs.y);
}

void Vec2D::operator += (const Vec2D& rhs)
{
  x += rhs.x;
  y += rhs.y;
}

Vec2D Vec2D::operator * (float value) const
{
  return Vec2D(this->x * value, this->y * value);
}

void Vec2D::operator *= (float value)
{
  this->x *= value;
  this->y *= value;
}

Vec2D Vec2D::operator / (float value) const
{
  return Vec2D(this->x / value, this->y / value);
}

} // PL_MATH