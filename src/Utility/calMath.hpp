#include <raylib-cpp.hpp>
#pragma once

float VectorMagnitude(raylib::Vector2 vector);
raylib::Vector2 UnitVectorisation(float mag, raylib::Vector2 vector);
float DistanceBetween(raylib::Vector2 v1, raylib::Vector2 v2);