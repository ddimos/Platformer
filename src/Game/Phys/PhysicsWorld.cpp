#include "PhysicsWorld.h"
#include "Game/Phys/Body.h"

namespace PL_PHYS
{

PhysicsWorld::PhysicsWorld(float dt)
    :
    m_DT(dt)
{
}

Body* PhysicsWorld::AddBody(/*args*/)
{
    m_Bodies.push_back(std::make_unique<Body>());
    return m_Bodies.back().get();
}

void PhysicsWorld::Step()
{
    for (auto& body : m_Bodies)
    {
        if (!body->isStatic)
        {
            body->ApplyForceToCenter(m_Gravity);
        }
    }

    for (auto& body : m_Bodies)
    {
        Integrate(body.get());
    }


    for (auto& body : m_Bodies)
    {
        body->force = 0.0f;
    }
}

void PhysicsWorld::Integrate(Body* body)
{
    if (body->isStatic)
    {
        return;
    }
    body->velocity += (body->force * body->invMass) + m_DT;
    body->position += body->velocity * m_DT;
}

} // PL_PHYS

