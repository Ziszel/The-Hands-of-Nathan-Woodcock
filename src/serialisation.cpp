#include "serialisation.hpp"
#include <fstream>

void SaveGameState(Player &player)
{

    // turn data into json
    nlohmann::json j = player;

    // save JSON to file
    std::ofstream file("THONW.sav");

    file << j << std::endl;

    file.close();
}

void LoadGameState()
{
    // verify a file exists, if so

    // read data

    // update current game with that data

    // if not, initialise new game

}