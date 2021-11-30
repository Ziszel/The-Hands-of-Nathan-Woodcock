#include <raylib-cpp.hpp>
#pragma once

class Tile
{
private:
    static int ID;
    int tileId;
    Texture2D texture;

public:
    const int width = 64;
    const int height = 64;
    Tile(Texture2D texture);
    void DrawTile(int x, int y);
    int getId();
};
