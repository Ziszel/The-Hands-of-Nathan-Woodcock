#include "ui.hpp"

UI::UI()
{
    this->healthPos = raylib::Vector2(0.0f, 0.0f);
}

void UI::Update(float deltaTime)
{
}

void UI::Draw(Player *player, int screenWidth)
{
    for (int i = player->health; i >= 0; i--)
    {
        healthPos.x = screenWidth - (healthWidth + healthPadding) * i;
        healthPos.y = 25;

        DrawRectangle(healthPos.x, healthPos.y, healthWidth, healthHeight, RED);
    }
}