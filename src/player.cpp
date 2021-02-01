#include "player.hpp"

Player::Player(Texture2D texture, raylib::Vector2 position)
{
	this->texture = texture;
	this->position = position;
    this->friction = 0.98f;
    this->speed = raylib::Vector2(0.0f, 0.0f);
}