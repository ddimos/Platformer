#include "Vec2D.h"


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