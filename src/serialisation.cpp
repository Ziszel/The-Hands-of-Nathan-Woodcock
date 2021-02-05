#include "serialisation.hpp"
#include <fstream>

void SaveGameState(Player &player)
{
    //const playerNs::Player p = player;
    // Hitting an undefined reference to nlohmann::to_json.
    // TODO: fix error to enable JSON serialisation/saving.

    //turn data into json
    nlohmann::json j;
    j["position.x"] = player.position.x;
    j["position.y"] = player.position.y;

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