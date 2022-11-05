#pragma once
#include <unordered_map>
#include <string>
#include "Building.h"

class Country
{
public:
	Country();
	Country(std::string country);

	// getters
	const Building getBuilding(std::string building);
	const std::unordered_map<std::string, Building> getBuildings();

	// setters

	void setBuildings(std::unordered_map<std::string, Building> &buildings);
	void setBuildings(std::unordered_map<std::string, Building> buildings);
	
	// methods

	void randomizeBuildingPos();

private:
	std::unordered_map<std::string, Building> buildings;
};

