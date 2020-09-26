#include "PhysicsWorld.h"
#include "Game/Phys/Body.h"
#include <iostream>
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
        if (body->type == Body::PhysType::DYNAMIC)
        {
            body->ApplyForceToCenter(m_Gravity);
        }
    }

    for (size_t i = 0; i < m_Bodies.size(); i++)
    {
        for (size_t j = i + 1; j < m_Bodies.size(); j++)
        {
            if ( m_Bodies[i]->type == Body::PhysType::STATIC
              && m_Bodies[j]->type == Body::PhysType::STATIC)
            {
                continue;
            }
            
            CollisionPair pair;
            pair.A = m_Bodies[i].get();
            pair.B = m_Bodies[j].get();

            if (pair.IsCollide())
            {
                m_Contacts.push_back(pair);
            }

        }
    }

    for (auto& pair : m_Contacts)
    {
        for (size_t i = 0; i < 10; i++)
        {
        pair.ResolveCollision();
            /* code */
        }
        
    }
    

    if (false && m_Contacts.size())
    {
        auto n = m_Contacts[0].normal;
std::cout<<m_Contacts[0].penetration << std::endl;  
std::cout<<n.x << " " << n.y << std::endl; 
    }
    for (auto& body : m_Bodies)
    {
        Integrate(body.get());
    }

    for (auto& pair : m_Contacts)
    {
        pair.CorrectPosition();
    }

    for (auto& body : m_Bodies)
    {
        body->force = 0.0f;
        // move somewhere
        body->shape.center = body->position;
    }
    m_Contacts.clear();
}

void PhysicsWorld::Integrate(Body* body)
{
    if (body->type == Body::PhysType::STATIC)
    {
        return;
    }
    body->velocity += (body->force * body->invMass) + m_DT;
    body->position += body->velocity * m_DT;
}

} // PL_PHYS

