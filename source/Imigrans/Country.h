#pragma once
#include <unordered_map>
#include <string>
#include "Building.h"

class Country
{
public:
	Country();
	Country(std::string country);

	const Building getBuilding(std::string building);

private:
	std::unordered_map<std::string, Building> buildings;
};

