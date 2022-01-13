#include "AABB.hpp"

AABB::AABB(){};
AABB::AABB(std::pair<float, float> centre, std::pair<float, float> extends)
{
    setVar(centre, extends);
}

void AABB::setVar(std::pair<float, float> centre, std::pair<float, float> extends)
{
    this->centre = centre;
    this->extends = extends;
}

bool AABB::testCollision(AABB other)
{
    if (this->max().first < other.min().first ||
    this->max().second < other.min().second ||
    this->min().first > other.max().first ||
    this->min().second > other.max().second)
    {
        return false;
    }

    return true;
}

std::pair<float, float> AABB::min()
{
    float x = this->centre.first - this->extends.first;
    float y = this->centre.second - this->extends.second;

    return std::pair<float, float> {x, y};
}
std::pair<float, float> AABB::max()
{
    float x = this->centre.first + this->extends.first;
    float y = this->centre.second + this->extends.second;

    return std::pair<float, float> {x, y};
}
std::pair<float, float> AABB::size()
{
    return std::pair<float, float> {this->extends.first * 2, this->extends.second * 2 };
}