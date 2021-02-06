#include "player.hpp"
#include <raylib-cpp.hpp>
#include <array>
#pragma once

// A class which represents an object to be scrolled.
class Scrollable
{
public:
	Texture2D texture;
	raylib::Vector2 position;
	int order;
	float distance;

	Scrollable(Texture2D texture, raylib::Vector2 position, int order, float distance);
};

void updateScrollables(std::array<Scrollable, 2> &scrollables, Player player);