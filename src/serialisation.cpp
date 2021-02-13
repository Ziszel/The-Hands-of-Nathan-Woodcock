#include "serialisation.hpp"

void SaveGameState(Player &player, std::array<Scrollable, 2> &scrollables)
{
    // Hitting an undefined reference to nlohmann::to_json. with namespaces.
    // using 'large' boilerplate version for now
    // TODO: Save individual objects instead of a stream of 'globalised' values.

    //turn data into json (I'm aware of how terrible this is currently)
    nlohmann::json j;
    j["player.position.x"] = player.position.x;
    j["player.position.y"] = player.position.y;
    j["background.position.x"] = scrollables[0].position.x;
    j["background.position.y"] = scrollables[0].position.y;
    j["midground.position.x"] = scrollables[1].position.x;
    j["midground.position.y"] = scrollables[1].position.y;

    // save JSON to file
    std::ofstream file("THONW.sav");

    file << std::setw(4) << j << std::endl;

    file.close();
}

void LoadGameState(Player &player, std::array<Scrollable, 2> &scrollables)
{
    // verify a file exists, if so load and convert to JSON, assign to player
    std::ifstream saveData("THONW.sav");
    if (saveData)
    {
        nlohmann::json j;
        saveData >> j;
        player.position.x = j["player.position.x"].get<float>();
        player.position.y = j["player.position.y"].get<float>();
        scrollables[0].position.x = j["background.position.x"].get<float>();
        scrollables[0].position.y = j["background.position.y"].get<float>();
        scrollables[1].position.x = j["background.position.x"].get<float>();
        scrollables[1].position.y = j["background.position.y"].get<float>();
    }
    else
    {
        std::cout << "There is no data to load." << std::endl;
    }
}