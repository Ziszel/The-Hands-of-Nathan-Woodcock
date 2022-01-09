#include "tile.hpp"

Tile::Tile(Texture2D texture)
{
    this->ID++;
    this->texture = texture;
    this->tileId = this->ID;

    aabb.setVar(this->centre,this->extends);
}

void Tile::DrawTile(int x, int y)
{
    DrawTexture(this->texture, x, y, WHITE);
}

int Tile::getId()
{
    return this->tileId;
}

int Tile::ID = 0;