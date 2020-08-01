#pragma once
#include "Game/Vec2D.h"
#include "Game/Texture.h"

#include "Game/SpriteRenderer.h"

#include <Extern/glm/glm.hpp>

class BaseObject
{
private:
    Vec2D m_Size;
    Vec2D m_Position;
    Vec2D m_Velocity;
    float m_Rotation;

    glm::vec3 m_Color;  // vec4 ?
    Texture2D m_Texture;

    bool m_IsStatic;
    bool m_IsDestroyed;

public:
    BaseObject();
    BaseObject(Vec2D pos,
               Vec2D size,
               Texture2D sprite,
               glm::vec3 color = glm::vec3(1.0f),
               Vec2D vel = Vec2D(0.0f, 0.0f));

    virtual void Draw(SpriteRenderer& renderer);
    virtual void Update(float dt) {}

public:
    Vec2D const& GetSize() const {return m_Size;}
    void SetSize(Vec2D const& size) {m_Size = size;}
    Vec2D const& GetPosition() const {return m_Position;}
    void SetPosition(Vec2D const& pos) {m_Position = pos;}
    Vec2D const& GetVelocity() const {return m_Velocity;}
    void SetVelocity(Vec2D const& vel) {m_Velocity = vel;}
    glm::vec3 const& GetColor() const {return m_Color;}
    void SetColor(glm::vec3 const& color) {m_Color = color;}
    void SetTexture(Texture2D const& tex) {m_Texture = tex;}

    bool const IsStatic() const {return m_IsStatic;}
    void SetIsStatic(bool isStatic) {m_IsStatic = isStatic;}
    bool const isDestroyed() const {return m_IsDestroyed;}
    void SetIsDestroyed(bool isDestroyed) {m_IsDestroyed = isDestroyed;}

};
