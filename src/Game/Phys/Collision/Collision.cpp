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
    bool const isOverlap = IsOverlapAABBvsAABB(p);

    if (!isOverlap)
    {
        return false;
    }
    
    

}

}