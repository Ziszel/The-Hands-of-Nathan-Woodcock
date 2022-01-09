#pragma once
#include <iostream>

class AABB {
private:
    // width and height of object / 2
    std::pair<float, float> centre;
    // 
    std::pair<float, float> extends;

public:
    AABB();
    AABB(std::pair<float, float> centre, std::pair<float, float> extends);

    void setVar(std::pair<float, float> centre, std::pair<float, float> extends);
    bool test(AABB other);
    // this will return a vector that is the top left of a position
    std::pair<float, float> min();
    // this will return a vector that is the bottom right of a position
    std::pair<float, float> max();
    std::pair<float, float> size();
};