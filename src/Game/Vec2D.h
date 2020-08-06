#pragma once
#include "Extern/glm/glm.hpp"

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

};
