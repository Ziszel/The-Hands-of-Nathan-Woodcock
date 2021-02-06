#include "player.hpp"
#include <nlohmann/json.hpp>
#include <iomanip>
#include <fstream>
#pragma once

void SaveGameState(Player &player);

void LoadGameState();
