#include <raylib-cpp.hpp>
#include <string>
#include <cstring>
#pragma once

// options will have:
// - text
// - selected property (bool)

class Option
{
private:
    char content[12];
    // startPos will come from Menu class
    raylib::Vector2 startPos;
    int padding = 10;

public:
    int w = 100;
    int h = 100;
    bool selected = false;

	Option(std::string content);

    void Update();
    void Draw(float x, float y);
};