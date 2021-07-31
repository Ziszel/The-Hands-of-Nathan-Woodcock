#include "menu.hpp"

Menu::Menu(Texture2D backgroundTex, raylib::Vector2 titlePos, std::string titleText, std::vector<Option> options)
{
    strcpy(this->titleText, titleText.c_str());
    this->backgroundTex = backgroundTex;
    this->titlePos = titlePos;
    this->options = options;

    options[0].selected = true;
}

void Menu::Update()
{
    // call option update loops here
}

void Menu::Draw(int screenWidth, int screenHeight)
{
    DrawTexture(this->backgroundTex, 0, 0, WHITE);
    DrawText(titleText, titlePos.x, titlePos.y, 24, BLACK);
    for (int i = 0; i <= options.size(); i++)
		{
			int posX = (screenWidth * 0.5) - (options[i].w * 0.5);
			int posY = screenHeight * 0.5 - (options[i].h + padding) * i;
            if (options[i].selected == true)
            {
                DrawRectangleLines(posX, posY, options[i].w, options[i].h, BLACK);
            }
			DrawRectangle(posX, posY, options[i].w, options[i].h, BLUE);
            options[i].Draw(posX, posY);
		}
}