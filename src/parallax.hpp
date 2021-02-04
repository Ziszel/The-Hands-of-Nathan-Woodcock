#include "player.hpp"
#include <raylib-cpp.hpp>
#include <array>
#pragma once

using namespace playerNs;

// "namespaces exist to avoid identical name conflicts. Allow encompasses entire codebases into a project" - Da Gonz
// using namespace raylib;

// A structure which represents an object to be scrolled.
// TODO: Turn this struct into a class :ok
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