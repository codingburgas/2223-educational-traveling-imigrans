#pragma once
#include <unordered_map>
#include <string>
#include "Building.h"

class Country
{
public:
	Country();
	Country(std::string country);

	~Country();
	// getters
	const Building getBuilding(std::string building);
	const std::unordered_map<std::string, Building> getBuildings();

	// setters

	void setBuildings(std::unordered_map<std::string, Building> &buildings);
	void setBuildingsInPos(float y);
	void setBuildings(std::unordered_map<std::string, Building> buildings);
	
	// methods

	void randomizeBuildingPos();
	void setBuildingDoor(std::string building);

private:
	std::unordered_map<std::string, Building> buildings;
};

