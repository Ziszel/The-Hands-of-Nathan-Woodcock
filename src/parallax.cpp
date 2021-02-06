#include "parallax.hpp"
#include "Utility/calMath.hpp"
#include <iostream>

Scrollable::Scrollable(Texture2D texture, raylib::Vector2 position, int order, float distance)
	{
		this->texture = texture;
		this->position = position;
		this->order = order;
		this->distance = distance;
	}

// A function that takes in an array of scrollable objects, and
// Moves them via their params in the update function.
void updateScrollables(std::array<Scrollable, 2> &scrollables, playerNs::Player player)
{
	player.direction = UnitVectorisation(VectorMagnitude(player.position), player.position);
	std::cout << "X: " << player.direction.x << std::endl;
	std::cout << " Y: " << player.direction.y << std::endl;
	for (int i = 0; i < scrollables.size(); i++)
	{
		//Scrollable s = scrollables.at(i);
		if (player.direction.x * player.speed.x > 0)
		{
			scrollables.at(i).position.x += (-player.speed.x / scrollables.at(i).distance);
		}
		else
		{
			scrollables.at(i).position.x -= (+player.speed.x / scrollables.at(i).distance);
		}
	}
}