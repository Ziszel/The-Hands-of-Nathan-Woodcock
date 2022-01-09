#include "player.hpp"

Player::Player(Texture2D texture, std::pair<float, float> position)
{
    this->texture = texture;
    this->position = position;
    this->positionOld = position;
    this->speed = std::pair<float, float>(0.0f, 0.0f);
    this->inAir = true;
    this->height = texture.height * 2;
    this->width = texture.width * 2;

    this->centre = {position.first, position.second};
    this->extends = extends = { width * 0.5, height * 0.5 };
    this->aabb.setVar(centre, extends);
}

void Player::Update(float deltaTime)
{
    positionOld = position;

    // Checks if player has input a key and moves if required
    int key = GetKeyPressed();

    xMovement(deltaTime);
    yMovement(deltaTime, key);

    // this controls whether or not the player can jump, replace with tiled
    // logic once implemented
    if (this->speed.second == 0)
    {
        this->inAir = false;
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
    if (this->inAir == true)
    {
        // player must now be in the air, stop them jumping again,
        // and slowly bring them down.
        this->speed.second += this->gravity * deltaTime;
    }

    // move the player relative to their speed
    this->position.first += this->speed.first;
    this->position.second += this->speed.second;
}

void Player::Draw()
{
    raylib::Vector2 rVectorPosition = {position.first, position.second};
    DrawTextureEx(this->texture, rVectorPosition, 0.0f, 2.0f, WHITE);
}

void Player::xMovement(float deltaTime)
{
    // TODO: Check if there is no input
    // If not then break out of loop here as a small optimisation

    float modifier = setModifier(deltaTime);

    if (modifier == this->friction)
    {
        this->speed.first *= modifier;
    }
    else
    {
        if ((this->speed.first + modifier) < this->maxSpeed && (this->speed.first + modifier) > -this->maxSpeed)
        {
            this->speed.first += modifier;
        }
    }
}

void Player::yMovement(float deltaTime, int key)
{
    if (IsKeyPressed('W') && this->inAir == false)
    {
        this->speed.second -= 500.0f * deltaTime;
        this->inAir = true;
    }
}

float Player::setModifier(float deltaTime)
{

    // TODO: Split out the friction and inAir calculations into separate functions
    if (IsKeyDown('A') && this->speed.first > -this->maxSpeed)
    {
        // moves the player slower in the air
        if (this->inAir == true)
        {
            return (-this->acceleration * 0.5) * deltaTime;
        }
        // allows player to quickly change direction
        else if (this->speed.first > 2)
        {
            return this->friction;
        }
        // moves the player at standard speed
        else
        {
            return (-this->acceleration) * deltaTime;
        }
    }
    if (IsKeyDown('D') && this->speed.first < this->maxSpeed)
    {
        if (this->inAir == true)
        {
            return (this->acceleration * 0.5) * deltaTime;
        }
        else if (this->speed.first < -2)
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