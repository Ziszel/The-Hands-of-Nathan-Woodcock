#include "serialisation.hpp"
#include <fstream>
#pragma once

using namespace playerNs;

void SaveGameState(Player &player)
{

    // collect data to parse
    int positionX = player.position.x;
    int positionY = player.position.y;

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