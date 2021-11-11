#include "parallax.hpp"
#include "Utility/calMath.hpp"

Scrollable::Scrollable(Texture2D texture, std::pair<float, float>position, int order, float distance)
	{
		this->texture = texture;
		this->position = position;
		this->order = order;
		this->distance = distance;
	}

// A function that takes in an array of scrollable objects, and
// Moves them via their params in the update function.
void updateScrollables(std::array<Scrollable, 2> &scrollables, Player player)
{
	player.direction = UnitVectorisation(VectorMagnitude(player.position), player.position);
	for (int i = 0; i < scrollables.size(); i++)
	{
		if (player.direction.first * player.speed.first > 0)
		{
			scrollables.at(i).position.first += (-player.speed.first / scrollables.at(i).distance);
		}
		else
		{
			scrollables.at(i).position.first -= (+player.speed.first / scrollables.at(i).distance);
		}
	}
}