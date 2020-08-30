#pragma once
#include "Game/Math/Math.h"

namespace PL_PHYS
{

class Body
{
public:
    PL_MATH::Vec2D position;
    PL_MATH::Vec2D velocity;
    PL_MATH::Vec2D force;
    float rotation;

//  float I;  // moment of inertia
//  float iI; // inverse inertia
    float mass;
    float invMass;

    bool isStatic;

//  float angularVelocity;
//  float torque;

//  float staticFriction;
//  float dynamicFriction;
//  float restitution;
public:
    Body(/* args */);
    
    void ApplyForceToCenter(PL_MATH::Vec2D const& force);
};

}