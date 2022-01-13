#pragma once
#include "AABB.hpp"
#include <raylib-cpp.hpp>
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/utility.hpp>

class Player
{
public:
	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
	    ar & position;
	    ar & health;
		ar & speed;
	}
	Texture2D texture;
	std::pair<float, float> position;
	std::pair<float, float> positionOld;
	std::pair<float, float> speed;
	std::pair<float, float> direction;
	const float maxSpeed = 12.0f;
	const float acceleration = 8.0f;
	const float friction = 0.92f;
	float width;
	float height;
	int health = 3;
	const float gravity = 10.0f;
	bool inAir;
	std::pair<float, float> centre;
	std::pair<float, float> extends;
	AABB aabb;

	Player(Texture2D texture, std::pair<float, float> position);
	Player() = default;

	void Update(float deltaTime);
	void xMovement(float deltaTime);
	void yMovement(float deltaTime, int key);
	float setModifier(float deltaTime);
	void Draw();
};