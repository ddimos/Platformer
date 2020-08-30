#pragma once

#include <vector>
#include <memory>

#include "Game/Math/Math.h"

namespace PL_PHYS
{
class Body;

class PhysicsWorld
{
private:
    std::vector<std::unique_ptr<Body>> m_Bodies;
    float const m_DT;
    PL_MATH::Vec2D m_Gravity = {0.0f, 1.0f};

public:
    PhysicsWorld(float dt);

    Body* AddBody(/*args*/);

    void Step();

private:
    void Integrate(Body* body);
};

} // PL_PHYS
