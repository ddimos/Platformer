#include "BaseObject.h"

using namespace PL_MATH;

BaseObject::BaseObject()
  :
  m_Size{1.0f}
  ,m_Position{}
  //...
{
}

BaseObject::BaseObject( Vec2D pos,
                        Vec2D size,
                        Texture2D sprite,
                        glm::vec3 color,
                        Vec2D vel)
  :
  m_Size{size}
  ,m_Position{pos}
  //...
{
}

void BaseObject::Draw(SpriteRenderer& renderer)
{
    renderer.DrawSprite(m_Texture, m_Position, m_Size, m_Rotation, m_Color);
}