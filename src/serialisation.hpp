#include "player.hpp"
#include "parallax.hpp"
#include <array>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/utility.hpp>
#pragma once

void SaveGameState(Player &player, std::array<Scrollable, 2> &scrollables);

void LoadGameState(Player &player, std::array<Scrollable, 2> &scrollables);
