#include "map.hpp"

Map::Map(std::string mapPath)
{
    this->mapPath = mapPath;
    // this is how you resize a 2D vector, thank Jesus
    mapData.resize(ROWS,std::vector<int>(COLS));
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

void Map::DrawMap(std::vector<Tile>tiles)
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

    int x = 0;
    int y = 0;

    // output to screen
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            for(auto tile : tiles)
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
        x = 0;
    }
}