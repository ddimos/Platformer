#pragma once
#include <cstdlib>

namespace PL_MATH
{

const float PI = 3.141592741f;
const float EPSILON = 0.0001f;

float Sqrt(float x);
float Max(float a, float b);

inline float Pow2(float x)
{
    return x*x;
}

inline float Abs(float v)
{
  return std::abs(v);
}
 
inline float Random(float l, float h)
{
  float a = (float)rand( );
  a /= RAND_MAX;
  a = (h - l) * a + l;
  return a;
}

inline bool Equal(float a, float b)
{
  // <= instead of < for NaN comparison safety
  return std::abs( a - b ) <= EPSILON;
}

inline bool BiasGreaterThan(float a, float b)
{
  const float k_biasRelative = 0.95f;
  const float k_biasAbsolute = 0.01f;
  return a >= b * k_biasRelative + a * k_biasAbsolute;
}

} // PL_MATH