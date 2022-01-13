#pragma once
#include <raylib-cpp.hpp>
#include "AABB.hpp"
#include <iostream>

#define TILESIZE 64

class Tile
{
private:
    static int ID;
    int tileId;
    Texture2D texture;

public:
    const int width = 64;
    const int height = 64;
    std::pair<float, float> centre = {0,0};
    std::pair<float, float> extends = {TILESIZE * 0.5,TILESIZE * 0.5};
    AABB aabb;

    Tile(Texture2D texture);
    void DrawTile(int x, int y);
    int getId();
};
