#include "map.hpp"

Map::Map(std::string mapPath)
{
    this->mapPath = mapPath;
    // this is how you resize a 2D vector, thank Jesus
    mapData.resize(ROWS, std::vector<int>(COLS));
    LoadMapData();
}

void Map::LoadMapData()
{
    int temp = 0;

    std::ifstream mapFile;
    mapFile.open(mapPath);

    if (mapFile.is_open())
    {
        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COLS; col++)
            {
                mapFile >> temp;
                //std::cout << typeid(temp).name() << std::endl;
                mapData[row][col] = temp;
            }
        }
    }
    mapFile.close();
}

int ::Map::LocateScrollablesDrawPos(std::vector<Tile> tiles)
{
    int count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (auto tile : tiles)
        {
            if (mapData[i][0] != 0)
            {
                std::cout << "mapData: " << mapData[i][0] << "\n";
                // x should be drawn in place of COLS, not ROWS
                return count;
            }

            count += TILESIZE;
        }
    }

    return 0;
}

bool Map::CheckMapCollision(Player p, std::vector<Tile> tiles)
{
    int x = MAPSTART;
    int y = MAPSTART;

    // output to screen
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {

            for (auto tile : tiles)
            {
                // update the centre of the tile
                // add flag so that this runs only once.
                tile.centre.first = x + TILESIZE / 2;
                tile.centre.second = y + TILESIZE / 2;

                if (mapData[i][j] != 0)
                {
                    // AABB player and tile (the '()' on aabb here looks wrong...)
                    return p.aabb.testCollision(tile.aabb);
                }
                x += TILESIZE;
            }
        y += TILESIZE;
        x = MAPSTART;
        }
    }

    return false;
}

void Map::DrawMap(std::vector<Tile> tiles)
{
    // output to console
    // for (int i = 0; i < ROWS; i++)
    // {
    //     for (int j = 0; j < COLS; j++)
    //     {
    //         std::cout << mapData[i][j];
    //     }
    //     std::cout << "\n";
    // }

    int x = MAPSTART;
    int y = MAPSTART;

    // output to screen
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {

            for (auto tile : tiles)
            {
                if (mapData[i][j] == tile.getId())
                {
                    // x should be drawn in place of COLS, not ROWS
                    tile.DrawTile(x, y);
                }
            }
            x += TILESIZE;
        }
        y += TILESIZE;
        x = MAPSTART;
    }
}