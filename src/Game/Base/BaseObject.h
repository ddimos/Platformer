#pragma once
#include "Game/Math/Vec2D.h"
#include "Game/Render/Texture.h"

#include "Game/Render/SpriteRenderer.h"

#include <Extern/glm/glm.hpp>

class BaseObject
{
protected:
    PL_MATH::Vec2D m_Size;
    PL_MATH::Vec2D m_Position;
    PL_MATH::Vec2D m_Velocity;
    float m_Rotation;

    glm::vec3 m_Color;  // vec4 ?
    Texture2D m_Texture;

    bool m_IsStatic;
    bool m_IsDestroyed;

public:
    BaseObject();
    BaseObject(PL_MATH::Vec2D pos,
               PL_MATH::Vec2D size,
               PL_MATH::Vec2D vel,
               float rot,
               Texture2D tex,
               glm::vec3 color = glm::vec3(1.0f),
               bool isStatic = false);

    virtual void Draw(SpriteRenderer& renderer);
    virtual void Update(float dt) {}

public:
    PL_MATH::Vec2D const& GetSize() const {return m_Size;}
    void SetSize(PL_MATH::Vec2D const& size) {m_Size = size;}
    PL_MATH::Vec2D const& GetPosition() const {return m_Position;}
    void SetPosition(PL_MATH::Vec2D const& pos) {m_Position = pos;}
    PL_MATH::Vec2D const& GetVelocity() const {return m_Velocity;}
    void SetVelocity(PL_MATH::Vec2D const& vel) {m_Velocity = vel;}
    glm::vec3 const& GetColor() const {return m_Color;}
    void SetColor(glm::vec3 const& color) {m_Color = color;}
    void SetTexture(Texture2D const& tex) {m_Texture = tex;}

    bool const IsStatic() const {return m_IsStatic;}
    void SetIsStatic(bool isStatic) {m_IsStatic = isStatic;}
    bool const isDestroyed() const {return m_IsDestroyed;}
    void SetIsDestroyed(bool isDestroyed) {m_IsDestroyed = isDestroyed;}

};

class Player : public BaseObject
{
public:
    Player( PL_MATH::Vec2D size,
            PL_MATH::Vec2D pos,
            PL_MATH::Vec2D vel,
            float rot,
            Texture2D texture,
            glm::vec3 color = glm::vec3(1.0f),
            bool isStatic = false);
    
    void Update(float dt) override;
};
