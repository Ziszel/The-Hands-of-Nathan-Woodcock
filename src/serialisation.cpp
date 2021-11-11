#include "serialisation.hpp"
#include "player.hpp"

void SaveGameState(Player &player, std::array<Scrollable, 2> &scrollables)
{
    // save player object as text to file
    std::ofstream file("THONW.sav");
    {
        boost::archive::text_oarchive oa(file);
        // write class instance to archive
        oa << player << scrollables[0] << scrollables[1];
    }
    file.close();
}

void LoadGameState(Player &player, std::array<Scrollable, 2> &scrollables)
{
    // verify a file exists, if so load and convert to JSON, assign to player
    std::ifstream saveData("THONW.sav");
    if (saveData)
    {
        boost::archive::text_iarchive ia(saveData);
        // read class state from archive
        ia >> player >> scrollables[0] >> scrollables[1];
    }
}