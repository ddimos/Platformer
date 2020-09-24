#include "BaseObject.h"
#include "Game/Input/Input.h"

#include "Game/Phys/Body.h"

using namespace PL_MATH;
using namespace PL_PHYS;

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
                        bool isStatic,
                        glm::vec3 color)
    :
     m_Size{size}
    ,m_Position{pos}
    ,m_Velocity{vel}
    ,m_Rotation{rot}
    ,m_Texture{texture}
    ,m_IsStatic{isStatic}
    ,m_Color{color}
    ,m_IsDestroyed{false}
{

}

void BaseObject::Draw(SpriteRenderer& renderer)
{
    renderer.DrawSprite(m_Texture, m_Position, m_Size, m_Rotation, m_Color);
}

// temporary
void BaseObject::Update(float dt)
{
    if (m_Body)
    {
        m_Position = m_Body->position;
        m_Velocity = m_Body->velocity;
        m_Rotation = m_Body->rotation;
    }
  
}

void BaseObject::SetBody(PL_PHYS::Body* body)
{
    assert(body);
    m_Body = body;
    m_Body->position = m_Position;
    m_Body->velocity = m_Velocity;
    m_Body->rotation = m_Rotation;
    m_Body->shape.center = m_Position;
    m_Body->shape.halfSize = m_Size / 2.0f;
    if(m_IsStatic)
    {
        m_Body->type = Body::PhysType::STATIC;
    }
}


Player::Player(PL_MATH::Vec2D size,
               PL_MATH::Vec2D pos,
               PL_MATH::Vec2D vel,
               float rot,
               Texture2D texture,
               bool isStatic,
               glm::vec3 color)
               :
               BaseObject(size, pos, vel, rot, texture, isStatic, color)
{

}

void Player::Update(float dt)
{
    if (Input::IsKeyPressed('A'))
    {
        m_Body->ApplyForceToCenter({ -1.0f, 0.0f });
    }
    else if (Input::IsKeyPressed('D'))
    { 
        m_Body->ApplyForceToCenter({ 1.0f, 0.0f });
    }

    if (Input::IsKeyPressed('W'))
    {
        m_Body->ApplyForceToCenter({ 0.0f, -1.0f });
    }
    else if (Input::IsKeyPressed('S'))
    {
        m_Body->ApplyForceToCenter({ 0.0f, 1.0f });
    }

    BaseObject::Update(dt);    
}
