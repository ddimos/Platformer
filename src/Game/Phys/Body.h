#pragma once
#include "Game/Math/Math.h"
#include "Collision/Shape.h"

namespace PL_PHYS
{

class Body
{
public:
    enum class PhysType
    {
        STATIC = 1,
        KINEMATIC,
        DYNAMIC
    };

    PL_MATH::Vec2D position;
    PL_MATH::Vec2D velocity;
    PL_MATH::Vec2D force;
    float rotation;

//  float I;  // moment of inertia
//  float iI; // inverse inertia
    float mass;
    float invMass;

//  float angularVelocity;
//  float torque;

//  float staticFriction;
//  float dynamicFriction;
//  float restitution;

    PhysType type = PhysType::DYNAMIC;
    Shape shape;
    
public:
    Body(/* args */);
    
    void ApplyForceToCenter(PL_MATH::Vec2D const& force);
};

}