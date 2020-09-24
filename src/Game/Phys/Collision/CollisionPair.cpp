#include "CollisionPair.h"
#include "Game/Phys/Body.h"
#include "Collision.h"

namespace PL_PHYS
{

bool CollisionPair::IsCollide()
{
    if (!A || !B)
    {
        return false;
    }

    if( A->shape.type == Shape::Type::AABB
     && B->shape.type == Shape::Type::AABB) 
    {
        return Collision::AABBvsAABB(*this);
    }
    
    return false;
}

}