#include <raylib-cpp.hpp>
#pragma once

class Player
{
public:
	Texture2D texture;
	raylib::Vector2 position;
	raylib::Vector2 speed;
	raylib::Vector2 direction;
	float friction;

	Player(Texture2D texture, raylib::Vector2 position);
};