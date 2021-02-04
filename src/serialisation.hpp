#include "player.hpp"
#include <nlohmann/json.hpp>
#pragma once

using namespace playerNs;

void SaveGameState(Player &player);

void LoadGameState();
