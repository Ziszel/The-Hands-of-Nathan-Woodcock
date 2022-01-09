#pragma once
#include "player.hpp"
#include <raylib-cpp.hpp>
#include <array>

// A class which represents an object to be scrolled.
class Scrollable
{
public:
	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
	    ar & position;
	    ar & order;
		ar & distance;
	}
	Texture2D texture;
	std::pair<float, float>position;
	int order;
	float distance;

	Scrollable(Texture2D texture, std::pair<float, float>position, int order, float distance);
};

void updateScrollables(std::array<Scrollable, 2> &scrollables, Player player);