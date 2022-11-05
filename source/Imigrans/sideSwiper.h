#pragma once
#include "main.h"
#include "Player.h"
#include "Country.h"
#include <unordered_map>

std::unordered_map<std::string,Country> makeCountries();

extern Player player;

extern sf::Clock frameTime;
extern sf::Time dt;
extern int mapSize;