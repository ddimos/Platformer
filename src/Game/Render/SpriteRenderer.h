#pragma once

#include <Extern/glm/glm.hpp>
#include <Extern/glm/gtc/matrix_transform.hpp>

#include "Game/Render/Texture.h"
#include "Game/Render/Shader.h"
#include "Game/Math/Vec2D.h"

class SpriteRenderer
{
private:
    Shader m_Shader;
    unsigned m_QuadVAO;

public:
    SpriteRenderer(Shader &shader);
    ~SpriteRenderer();
    void DrawSprite(
        Texture2D &texture,
        PL_MATH::Vec2D const& position, 
        PL_MATH::Vec2D const& size = PL_MATH::Vec2D(10.0f), 
        float rotate = 0.0f, 
        glm::vec3 color = glm::vec3(1.0f));

private:
    void InitRenderData();
};
