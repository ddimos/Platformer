#include "BaseObject.h"
#include "Game/Input/Input.h"

using namespace PL_MATH;

BaseObject::BaseObject()
    :
     m_Size{1.0f}
    ,m_Position{0.0f}
    ,m_Velocity{0.0f}
    ,m_Rotation{0.0f}
    ,m_Color{glm::vec3(1.0f)}
    ,m_Texture{}
    ,m_IsStatic{false}
    ,m_IsDestroyed{false}
{
}

BaseObject::BaseObject( Vec2D size,
                        Vec2D pos,
                        Vec2D vel,
                        float rot,
                        Texture2D texture,
                        glm::vec3 color,
                        bool isStatic)
    :
     m_Size{size}
    ,m_Position{pos}
    ,m_Velocity{vel}
    ,m_Rotation{rot}
    ,m_Texture{texture}
    ,m_Color{color}
    ,m_IsStatic{isStatic}
    ,m_IsDestroyed{false}
{

}

void BaseObject::Draw(SpriteRenderer& renderer)
{
    renderer.DrawSprite(m_Texture, m_Position, m_Size, m_Rotation, m_Color);
}

Player::Player(PL_MATH::Vec2D size,
               PL_MATH::Vec2D pos,
               PL_MATH::Vec2D vel,
               float rot,
               Texture2D texture,
               glm::vec3 color,
               bool isStatic)
               :
               BaseObject(size, pos, vel, rot, texture, color, isStatic)
{

}

void Player::Update(float dt)
{
    if (Input::IsKeyPressed('A'))
    {
        m_Position.x -= m_Velocity.x * dt;
    }
    else if (Input::IsKeyPressed('D'))
    {
        m_Position.x += m_Velocity.x * dt;
    }

    if (Input::IsKeyPressed('W'))
    {
        m_Position.y -= m_Velocity.y * dt;
    }
    else if (Input::IsKeyPressed('S'))
    {
        m_Position.y += m_Velocity.y * dt;
    }    
}