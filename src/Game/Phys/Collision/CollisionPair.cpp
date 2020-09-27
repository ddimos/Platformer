#include "CollisionPair.h"
#include "Game/Phys/Body.h"
#include "Collision.h"

namespace PL_PHYS
{
using namespace PL_MATH;

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

void CollisionPair::ResolveCollision()
{
    if (!A || !B)
    {
        return;
    }

    Vec2D const velFromAtoB = B->velocity - A->velocity;

    float const velAlongN = Vec2D::Dot(velFromAtoB, normal);
    // moving away each other
    if (velAlongN > 0.0f)
    {
        return;
    }

    // restitution
    float const e = 0.8f; // TODO: min( A.restitution, B.restitution)

    float const j = -(1 - e) * velAlongN / (A->invMass + B->invMass);
    Vec2D const impulse = j * normal;
    if (A->type == Body::PhysType::DYNAMIC)
    {
        A->velocity -= A->invMass * impulse;
        A->velocity *= 0.999f;
    }
    if (B->type == Body::PhysType::DYNAMIC)
    {
        B->velocity += A->invMass * impulse;
        B->velocity *= 0.999f;
    }
}

void CollisionPair::CorrectPosition()
{
    if (!A || !B)
    {
        return;
    }

    float const percent = 0.4f;
    float const kSlop = 0.05f;
    Vec2D const correction = (Max(penetration - kSlop, 0.0f) / (A->invMass + B->invMass)) * percent * normal;

    if (A->type == Body::PhysType::DYNAMIC)
    {
        A->position -= A->invMass * correction;
    }
    if (B->type == Body::PhysType::DYNAMIC)
    {
        B->position += A->invMass * correction;
    }
}

}