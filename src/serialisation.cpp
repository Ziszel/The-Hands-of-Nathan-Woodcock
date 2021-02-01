#include "serialisation.hpp"
#include <jansson.h>
#include <fstream>
#pragma once

void SaveGameState(Player &player)
{
    // collect data to parse
    int positionX = player.position.x;
    int positionY = player.position.y;

    // turn data into json

    // save JSON to file
    std::ofstream file("THONW.sav");

    file << positionX << std::endl;

    file.close();
}

void LoadGameState()
{
    // verify a file exists, if so

    // read data

    // update current game with that data

    // if not, initialise new game

}