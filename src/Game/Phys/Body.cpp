#include "Body.h"

namespace PL_PHYS
{

Body::Body()
    :
     position{0.0f}
    ,velocity{0.0f}
    ,force{0.0f}
    ,rotation{0.0f}
    ,mass{1.0f}
    ,invMass{1.0f}
    ,isStatic{false}
{
}

void Body::ApplyForceToCenter(PL_MATH::Vec2D const& force)
{
    this->force += force;
}

}