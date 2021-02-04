#include <raylib-cpp.hpp>
#include <nlohmann/json.hpp>
#pragma once

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
	};

	void to_json(nlohmann::json &j, const Player &p);

} // namespace playerNS