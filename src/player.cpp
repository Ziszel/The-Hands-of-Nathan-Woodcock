#include "player.hpp"

void to_json(nlohmann::json &j, const Player &p)
{
    j = nlohmann::json{{"position.x", p.position.x}, {"position.y", p.position.y}};
}

void from_json(const nlohmann::json &j, Player &p)
{
    j.at("position.x").get_to(p.position.x);
    j.at("position.y").get_to(p.position.y);
}

Player::Player(Texture2D texture, raylib::Vector2 position)
{
    this->texture = texture;
    this->position = position;
    this->speed = raylib::Vector2(0.0f, 0.0f);
    this->inAir = false;
}