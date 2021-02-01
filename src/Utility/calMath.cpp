#include "calMath.hpp"

float VectorMagnitude(raylib::Vector2 vector)
{
	return sqrt((vector.x * vector.x) + (vector.y * vector.y));
}

raylib::Vector2 UnitVectorisation(float mag, raylib::Vector2 vector)
{
	float x = (vector.x / mag);
	float y = (vector.y / mag);
	return raylib::Vector2(x, y);
}

float DistanceBetween(raylib::Vector2 v1, raylib::Vector2 v2)
{
	return sqrt(v1.x - v2.x) * 2 + (v1.y - v2.y) * 2;
}