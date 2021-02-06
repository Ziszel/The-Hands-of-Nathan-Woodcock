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

void LoadGameState(Player &player)
{
    // verify a file exists, if so load and convert to JSON, assign to player
    std::ifstream saveData("THONW.sav");
    if (saveData)
    {
        nlohmann::json j;
        saveData >> j;
        player.position.x = j["position.x"].get<float>();
        player.position.y = j["position.y"].get<float>();
    }
    else
    {
        std::cout << "There is no data to load." << std::endl;
    }

    // read data

    // update current game with that data

    // if not, initialise new game

}