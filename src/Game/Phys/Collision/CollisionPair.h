#pragma once
#include "Game/Math/Math.h"

namespace PL_PHYS
{
class Body;

struct CollisionPair
{
    Body*           A = nullptr;
    Body*           B = nullptr;
    float           penetration = 0.0f;
    PL_MATH::Vec2D  normal = {0.0f};

    bool IsCollide();
    void ResolveCollision();
    void CorrectPosition();
};

}
