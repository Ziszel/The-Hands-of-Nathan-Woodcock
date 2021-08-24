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
    this->height = texture.height * 0.5;
    this->width = texture.width * 0.5;
}

void Player::Update(float deltaTime)
{
    // Checks if player has moved left or right on the x axis
    // and applies 'physics' to give feel
    xMovement(deltaTime);

    // Checks if the player has jumped and applies 'physics' to give feel
    yMovement(deltaTime);

    // this controls if the player is on the floor, replace with tiled
    // logic once implemented
    if (this->position.y > 240)
    {
        this->inAir = false;
        this->speed.y = 0;
        this->position.y = 240;
    }

    // Test for health system, to be removed
    if (IsKeyPressed('J'))
    {
        if (this->health > 0)
        {
            this->health--;
        }
    }

    // move the player relative to their speed
    this->position.x += this->speed.x;
    this->position.y += this->speed.y;
}

void Player::Draw()
{
    DrawTextureEx(this->texture, this->position, 0.0f, 2.0f, WHITE);
}

void Player::xMovement(float deltaTime)
{
    if (IsKeyDown('A') && this->speed.x > -this->maxSpeed)
    {
        if (this->inAir == false)
        {
            if (this->speed.x > 2)
            {
                this->speed.x *= this->friction;
            }
            else
            {
                this->speed.x += (-this->acceleration) * deltaTime;
            }
        }
        else
        {
            this->speed.x += (-this->acceleration * 0.5) * deltaTime;
        }
    }
    else if (IsKeyDown('D') && this->speed.x < this->maxSpeed)
    {
        if (this->inAir == false)
        {
            if (this->speed.x < -2)
            {
                this->speed.x *= this->friction;
            }
            else
            {
                this->speed.x += (this->acceleration) * deltaTime;
            }
        }
        else
        {
            this->speed.x += (this->acceleration * 0.5) * deltaTime;
        }
    }
    // Not sure why this fixes the camera issue
    else if (IsKeyDown('A') || IsKeyDown('D') && this->speed.x == this->speed.x)
    {
        this->speed.x = this->speed.x;
    }
    else if (this->inAir == false)
    {
        this->speed.x *= this->friction;
    }
}

void Player::yMovement(float deltaTime)
{
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
}