#include "player.hpp"
#include <nlohmann/json.hpp>
#pragma once

void SaveGameState(playerNs::Player &player);

void LoadGameState();
