#include "Mat2D.h"
#include <cmath>

namespace PL_MATH
{

Mat2D::Mat2D()
{
}

Mat2D::Mat2D(float radians)
{
    Set(radians);
}

Mat2D::Mat2D(float m00, float m01, float m10, float m11)
    : m00(m00), m01(m01)
    , m10(m10), m11(m11)
{
}

void Mat2D::Set(float radians)
{
    float const c = std::cos(radians);
    float const s = std::sin(radians);

    m00 = c; m01 = -s;
    m10 = s; m11 =  c;
}

Mat2D Mat2D::Abs() const
{
    return Mat2D(
        std::abs(m00), std::abs(m01),
        std::abs(m10), std::abs(m11));
}

Vec2D Mat2D::AxisX() const
{
    return Vec2D(m00, m10);
}

Vec2D Mat2D::AxisY() const
{
    return Vec2D(m01, m11);
}

Mat2D Mat2D::Transpose() const
{
    return Mat2D(m00, m10, m01, m11);
}

Vec2D const Mat2D::operator*(Vec2D const& rhs) const
{
    return Vec2D(m00 * rhs.x + m01 * rhs.y, m10 * rhs.x + m11 * rhs.y);
}

Mat2D const Mat2D::operator*(Mat2D const& rhs) const
{
    return Mat2D(
      m[0][0] * rhs.m[0][0] + m[0][1] * rhs.m[1][0],
      m[0][0] * rhs.m[0][1] + m[0][1] * rhs.m[1][1],
      m[1][0] * rhs.m[0][0] + m[1][1] * rhs.m[1][0],
      m[1][0] * rhs.m[0][1] + m[1][1] * rhs.m[1][1]
    );
}

} // PL_MATH