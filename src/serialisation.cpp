#include "serialisation.hpp"

void SaveGameState(Player &player)
{
    // Hitting an undefined reference to nlohmann::to_json. with namespaces.
    // using 'large' boilerplate version for now

    //turn data into json
    nlohmann::json j;
    j["position.x"] = player.position.x;
    j["position.y"] = player.position.y;

    // save JSON to file
    std::ofstream file("THONW.sav");

    file << std::setw(4) << j << std::endl;

    file.close();
}

void LoadGameState()
{
    // verify a file exists, if so
    // if ()
    // {
    //     std::ifstream i("THONW.sav");
    //     nlohmann::json j;
    //     i >> j;
    // }

    // read data

    // update current game with that data

    // if not, initialise new game

}