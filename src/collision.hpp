#include "player.hpp"
#include "tile.hpp"
#include <vector>

class Collision
{
private:
    /* data */
public:
    Collision(/* args */);
    ~Collision();
    static bool BoundingBoxPlayerAndTile(Player p, std::vector<Tile> tiles);
};