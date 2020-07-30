#pragma once

#include <Extern/glm/glm.hpp>
#include <Extern/glm/gtc/matrix_transform.hpp>

#include "Game/Texture.h"
#include "Game/Shader.h"

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
        glm::vec2 position, 
        glm::vec2 size = glm::vec2(10.0f, 10.0f), 
        float rotate = 0.0f, 
        glm::vec3 color = glm::vec3(1.0f));

private:
    void InitRenderData();
};
