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

void Player::Update(float deltaTime)
{
    if (IsKeyDown('A') && this->speed.x > -this->maxSpeed)
    {
        this->speed.x += -this->acceleration * deltaTime;
    }
    else if (IsKeyDown('D') && this->speed.x < this->maxSpeed)
    {
        this->speed.x += this->acceleration * deltaTime;
    }
    else if (this->inAir == false)
    {
        this->speed.x *= this->friction;
    }

    if (IsKeyPressed('W') && this->inAir == false)
    {
        // move player up.
        this->speed.y -= 500.0f * deltaTime;
        // We are now in the air
        this->inAir = true;
    }
    if (this->position.y < this->groundHeight && this->inAir == true)
    {
        // player must now be in the air, stop them jumping again,
        // and slowly bring them down.
        this->speed.y += this->gravity * deltaTime;
    }
    // this controls if the player is on the floor, replace with tiled
    // logic once implemented
    if (this->position.y > 240)
    {
        this->inAir = false;
        this->speed.y = 0;
        this->position.y = 240;
    }

    if (IsKeyPressed('J'))
    {
        if (this->health > 0)
        {
            this->health--;
        }
    }

    this->position.x += this->speed.x;
    this->position.y += this->speed.y;
}

void Player::Draw()
{
    DrawTextureEx(this->texture, this->position, 0.0f, 2.0f, WHITE);
}