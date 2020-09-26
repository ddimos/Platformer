#pragma once

namespace PL_PHYS
{

struct CollisionPair;

class Collision
{
public:
    static bool AABBvsAABB(CollisionPair &);
};

}