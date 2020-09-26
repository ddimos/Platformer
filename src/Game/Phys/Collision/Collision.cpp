#include "Collision.h"
#include "CollisionPair.h"
#include "Game/Phys/Body.h"

namespace PL_PHYS
{
using namespace PL_MATH;

bool IsOverlapAABBvsAABB(CollisionPair const& p)
{
    if (Abs(p.A->shape.center.x - p.B->shape.center.x) > (p.A->shape.halfSize.x + p.B->shape.halfSize.x))
    {
        return false;
    }
    if (Abs(p.A->shape.center.y - p.B->shape.center.y) > (p.A->shape.halfSize.y + p.B->shape.halfSize.y))
    {
        return false;
    }
    return true;
}

bool Collision::AABBvsAABB(CollisionPair & p)
{
    Vec2D const fromAtoB = p.B->shape.center - p.A->shape.center;
    float const xOverlap = (p.A->shape.halfSize.x + p.B->shape.halfSize.x) - Abs(fromAtoB.x);

    if (xOverlap > 0.0f)
    {
        float const yOverlap = (p.A->shape.halfSize.y + p.B->shape.halfSize.y) - Abs(fromAtoB.y);

        if (yOverlap > 0.0f)
        {
            if (xOverlap > yOverlap)
            {
                p.penetration = yOverlap;
                (fromAtoB.y > 0.0f)
                 ? p.normal = Vec2D(0.0f, 1.0f)
                 : p.normal = Vec2D(0.0f, -1.0f);
            }
            else
            {
                p.penetration = xOverlap;
                (fromAtoB.x > 0.0f)
                 ? p.normal = Vec2D(1.0f, 0.0f)
                 : p.normal = Vec2D(-1.0f, 0.0f);    
            }
            return true;
        }
    }
    
    return false;
}

}