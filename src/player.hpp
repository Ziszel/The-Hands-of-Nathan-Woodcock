#include <raylib-cpp.hpp>
#include <nlohmann/json.hpp>
#pragma once

// "namespaces exist to avoid identical name conflicts.
// Allow encompassing entire codebases into a project" - Da Gonz
namespace playerNs
{
	class Player
	{
	public:
		Texture2D texture;
		raylib::Vector2 position;
		raylib::Vector2 speed;
		raylib::Vector2 direction;
		float friction;

		Player(Texture2D texture, raylib::Vector2 position);
		//Player() = default;
	};

	//void to_json(nlohmann::json &j, const Player &p);
	//void from_json(const nlohmann::json &j, Player &p);

} // namespace playerNS