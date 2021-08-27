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
    // Checks if player has input a key and moves if required
    int key = GetKeyPressed();

    xMovement(deltaTime);
    yMovement(deltaTime, key);

    // this controls whether or not the player can jump, replace with tiled
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

    // apply gravity if the player is in the air
    if (this->position.y < this->groundHeight && this->inAir == true)
    {
        // player must now be in the air, stop them jumping again,
        // and slowly bring them down.
        this->speed.y += this->gravity * deltaTime;
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
    // TODO: Check if there is no input
    // If not then break out of loop here as a small optimisation

    float modifier = setModifier(deltaTime);

    if (modifier == this->friction)
    {
        this->speed.x *= modifier;
    }
    else
    {
        if ((this->speed.x + modifier) < this->maxSpeed && (this->speed.x + modifier) > -this->maxSpeed)
        {
            this->speed.x += modifier;
        }
    }

}

void Player::yMovement(float deltaTime, int key)
{
    if (IsKeyPressed('W') && this->inAir == false)
    {
        this->speed.y -= 500.0f * deltaTime;
        this->inAir = true;
    }
}

float Player::setModifier(float deltaTime)
{

    // TODO: Split out the friction and inAir calculations into separate functions
    if (IsKeyDown('A') && this->speed.x > -this->maxSpeed)
    {
        // moves the player slower in the air
        if (this->inAir == true)
        {
            return (-this->acceleration * 0.5) * deltaTime;
        }
        // allows player to quickly change direction
        else if (this->speed.x > 2)
        {
            return this->friction;
        }
        // moves the player at standard speed
        else
        {
            return (-this->acceleration) * deltaTime;
        }
    }
    if (IsKeyDown('D') && this->speed.x < this->maxSpeed)
    {
        if (this->inAir == true)
        {
            return (this->acceleration * 0.5) * deltaTime;
        }
        else if (this->speed.x < -2)
        {
            return this->friction;
        }
        else
        {
            return (this->acceleration) * deltaTime;
        }
    }
    if (this->inAir == false)
    {
        return this->friction;
    }
    return 0.0f;
}
