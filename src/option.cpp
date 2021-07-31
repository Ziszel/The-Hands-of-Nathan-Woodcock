#include "option.hpp"

Option::Option(std::string content)
{
    strcpy(this->content, content.c_str());
}

void Option::Update()
{

}

void Option::Draw(float x, float y)
{
    this->startPos = raylib::Vector2(x, y);
    std::cout << this->startPos.x << "\n";
    DrawText(content, startPos.x + padding, startPos.y + padding, 12, LIGHTGRAY);
}