#include "calMath.hpp"

float VectorMagnitude(std::pair<float, float>vector)
{
	return sqrt((vector.first * vector.first) + (vector.second * vector.second));
}

std::pair<float, float> UnitVectorisation(float mag, std::pair<float, float>vector)
{
	float x = (vector.first / mag);
	float y = (vector.second / mag);
	return std::pair<float, float>(x, y);
}

float DistanceBetween(std::pair<float, float>v1, std::pair<float, float>v2)
{
	return sqrt(v1.first - v2.first) * 2 + (v1.second - v2.second) * 2;
}