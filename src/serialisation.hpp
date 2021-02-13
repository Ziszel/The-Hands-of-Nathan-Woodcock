#include "player.hpp"
#include "parallax.hpp"
#include <nlohmann/json.hpp>
#include <array>
#include <iomanip>
#include <iostream>
#include <fstream>
#pragma once

void SaveGameState(Player &player, std::array<Scrollable, 2> &scrollables);

void LoadGameState(Player &player, std::array<Scrollable, 2> &scrollables);
