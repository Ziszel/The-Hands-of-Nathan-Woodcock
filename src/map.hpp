#pragma once
#include "tile.hpp"
#include "parallax.hpp"
#include "player.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <typeinfo>
#include <raylib-cpp.hpp>

#define TILESIZE 64
#define MAPSTART 0

class Map
{
private:
    const int ROWS = 16;
    const int COLS = 64;
    std::vector<std::vector<int>> mapData;
    std::string mapPath;

public:
    Map(std::string mapPath);
    void LoadMapData(); // this will load in the map data from a file, and fill mapData with it
    void DrawMap(std::vector<Tile> tiles);
    int LocateScrollablesDrawPos(std::vector<Tile> tiles);
    bool CheckMapCollision(Player p, std::vector<Tile> tiles);
};
