#include <raylib-cpp.hpp>
#include <nlohmann/json.hpp>
#pragma once

// "namespaces exist to avoid identical name conflicts.
// Allow encompassing entire codebases into a project" - Da Gonz
class Player
{
public:
	Texture2D texture;
	raylib::Vector2 position;
	raylib::Vector2 speed;
	raylib::Vector2 direction;
	const float maxSpeed = 12.0f;
	const float acceleration = 8.0f;
	const float friction = 0.92f;
	const int groundHeight = 240;
	const float gravity = 10.0f;
	bool inAir;

	Player(Texture2D texture, raylib::Vector2 position);
	Player() = default;
};

//void to_json(nlohmann::json &j, const Player &p);
//void from_json(const nlohmann::json &j, Player &p);