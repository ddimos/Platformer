#pragma once
#include "Game/Math/Math.h"

namespace PL_PHYS
{

struct Shape
{
    enum class Type
    {
        none = 0,
        CIRCLE,
        AABB
    };

    Type            type = Type::AABB; // for now only AABB
    PL_MATH::Vec2D  center = {0.0f};
    PL_MATH::Vec2D  halfSize = {0.0f};
};

//struct AABB : public Shape
//{
//    AABB() : type(Shape::Type::AABB) {}
//
//};



}