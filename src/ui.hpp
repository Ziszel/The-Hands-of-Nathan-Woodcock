#pragma once
#include <raylib-cpp.hpp>
#include "player.hpp"

class UI
{
private:
    const int healthWidth = 25;
    const int healthHeight = 25;
    const int healthPadding = 10;
    raylib::Vector2 healthPos;

public:
    UI();

    void Update(float deltaTime);
    void Draw(Player *player, int screenWidth);

};