#include <raylib-cpp.hpp>
#pragma once

float VectorMagnitude(std::pair<float, float>vector);
std::pair<float, float> UnitVectorisation(float mag, std::pair<float, float>vector);
float DistanceBetween(std::pair<float, float>v1, std::pair<float, float>v2);