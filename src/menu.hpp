#pragma once
#include "option.hpp"
#include <vector>
#include <raylib-cpp.hpp>
#include <string>
#include <cstring>
#include <iostream>

class Menu
{

// Each menu will have:
// - a certain amount of options
// -- an option is a clickable raylib rectangle (button) that is drawn at a certain point in the screen
// -- the other options will be drawn vertically down, with padding between
// - a background texture
// - potentially music
// - Title text
// - Will need an 'array of option objects here'
private:
    // think of a way of dynamically populating this on creation
    std::vector<Option> options;
    int padding = 20;
    char titleText[24];

public:
	Texture2D backgroundTex;
	raylib::Vector2 titlePos;
	raylib::Vector2 optionStartPos;

	Menu(Texture2D backgroundTex, raylib::Vector2 position, std::string titleText, std::vector<Option> options);

    void Update();
    void Draw(int screenWidth, int screenHeight);
};