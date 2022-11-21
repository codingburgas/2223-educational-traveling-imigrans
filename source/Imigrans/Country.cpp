#include "Country.h"
#include "sideSwiper.h"
#include <random>
Country::Country() :
	buildings(std::unordered_map<std::string, Building>())
{
}


Country::Country(std::string country)
{
	float npcAnimSpeed = 13.f;
	/*
		  gr - germany
		  it - italy
		  en - england
		  fr - france
		  rm - romania
		  bg - bulgaria
		  sp - spain
		  pl - poland
	*/

	if (country == "gr") // germany
	{
		// bank

		t[0].loadFromFile("assets/building/bank/outside.png");
		t[1].loadFromFile("assets/building/bank/inside.png");
		t[2].loadFromFile("assets/npc/germany/bank/spriteSheet.png");
		buildings.insert({ "bank",
			Building(&t[0], &t[1], &t[2], sf::Vector2u(2,1), npcAnimSpeed, false) });
		// bar

		t[3].loadFromFile("assets/building/bar/outside.png");
		t[4].loadFromFile("assets/building/bar/inside.png");
		t[5].loadFromFile("assets/npc/germany/hotel/spriteSheet.png");
		buildings.insert({ "bar",
			Building(&t[3], &t[4], &t[5], sf::Vector2u(2,1), npcAnimSpeed, false) });


		// restaurant

		t[6].loadFromFile("assets/building/restaurant/outside.png");
		t[7].loadFromFile("assets/building/restaurant/inside.png");
		t[8].loadFromFile("assets/npc/germany/restaurant/spriteSheet.png");
		buildings.insert({ "restaurant",
			Building(&t[6], &t[7], &t[8], sf::Vector2u(2,1), npcAnimSpeed, true) });
	}
	else if (country == "it") // italy
	{
		// bank

		t[0].loadFromFile("assets/building/bank/outside.png");
		t[1].loadFromFile("assets/building/bank/inside.png");
		t[2].loadFromFile("assets/npc/italy/bank/spriteSheet.png");
		buildings.insert({ "bank",
			Building(&t[0], &t[1], &t[2], sf::Vector2u(2,1), npcAnimSpeed, false) });
		// bar

		t[3].loadFromFile("assets/building/bar/outside.png");
		t[4].loadFromFile("assets/building/bar/inside.png");
		t[5].loadFromFile("assets/npc/italy/hotel/spriteSheet.png");
		buildings.insert({ "bar",
			Building(&t[3], &t[4], &t[5], sf::Vector2u(2,1), npcAnimSpeed, false) });


		// restaurant

		t[6].loadFromFile("assets/building/restaurant/outside.png");
		t[7].loadFromFile("assets/building/restaurant/inside.png");
		t[8].loadFromFile("assets/npc/italy/restaurant/spriteSheet.png");
		buildings.insert({ "restaurant",
			Building(&t[6], &t[7], &t[8], sf::Vector2u(2,1), npcAnimSpeed, true) });
	}
	else if (country == "en") // england
	{
		// bank

		t[0].loadFromFile("assets/building/bank/outside.png");
		t[1].loadFromFile("assets/building/bank/inside.png");
		t[2].loadFromFile("assets/npc/england/bank/spriteSheet.png");
		buildings.insert({ "bank",
			Building(&t[0], &t[1], &t[2], sf::Vector2u(2,1), npcAnimSpeed, false) });
		// bar

		t[3].loadFromFile("assets/building/bar/outside.png");
		t[4].loadFromFile("assets/building/bar/inside.png");
		t[5].loadFromFile("assets/npc/england/hotel/spriteSheet.png");
		buildings.insert({ "bar",
			Building(&t[3], &t[4], &t[5], sf::Vector2u(2,1), npcAnimSpeed, false) });


		// restaurant

		t[6].loadFromFile("assets/building/restaurant/outside.png");
		t[7].loadFromFile("assets/building/restaurant/inside.png");
		t[8].loadFromFile("assets/npc/england/restaurant/spriteSheet.png");
		buildings.insert({ "restaurant",
			Building(&t[6], &t[7], &t[8], sf::Vector2u(2,1), npcAnimSpeed, true) });
	}
	else if (country == "fr") // france
	{
		// bank

		t[0].loadFromFile("assets/building/bank/outside.png");
		t[1].loadFromFile("assets/building/bank/inside.png");
		t[2].loadFromFile("assets/npc/france/bank/spriteSheet.png");
		buildings.insert({ "bank",
			Building(&t[0], &t[1], &t[2], sf::Vector2u(2,1), npcAnimSpeed, false) });
		// bar

		t[3].loadFromFile("assets/building/bar/outside.png");
		t[4].loadFromFile("assets/building/bar/inside.png");
		t[5].loadFromFile("assets/npc/france/hotel/spriteSheet.png");
		buildings.insert({ "bar",
			Building(&t[3], &t[4], &t[5], sf::Vector2u(2,1), npcAnimSpeed, false) });


		// restaurant

		t[6].loadFromFile("assets/building/restaurant/outside.png");
		t[7].loadFromFile("assets/building/restaurant/inside.png");
		t[8].loadFromFile("assets/npc/france/restaurant/spriteSheet.png");
		buildings.insert({ "restaurant",
			Building(&t[6], &t[7], &t[8], sf::Vector2u(2,1), npcAnimSpeed, true) });
	}
	else if (country == "rm") // romania
	{
		// bank

		t[0].loadFromFile("assets/building/bank/outside.png");
		t[1].loadFromFile("assets/building/bank/inside.png");
		t[2].loadFromFile("assets/npc/romania/bank/spriteSheet.png");
		buildings.insert({ "bank",
			Building(&t[0], &t[1], &t[2], sf::Vector2u(2,1), npcAnimSpeed, false) });
		// bar

		t[3].loadFromFile("assets/building/bar/outside.png");
		t[4].loadFromFile("assets/building/bar/inside.png");
		t[5].loadFromFile("assets/npc/romania/hotel/spriteSheet.png");
		buildings.insert({ "bar",
			Building(&t[3], &t[4], &t[5], sf::Vector2u(2,1), npcAnimSpeed, false) });


		// restaurant

		t[6].loadFromFile("assets/building/restaurant/outside.png");
		t[7].loadFromFile("assets/building/restaurant/inside.png");
		t[8].loadFromFile("assets/npc/romania/restaurant/spriteSheet.png");
		buildings.insert({ "restaurant",
			Building(&t[6], &t[7], &t[8], sf::Vector2u(2,1), npcAnimSpeed, true) });
	}
	else if (country == "bg") // bulgaria
	{
		// bank

		t[0].loadFromFile("assets/building/bank/outside.png");
		t[1].loadFromFile("assets/building/bank/inside.png");
		t[2].loadFromFile("assets/npc/bulgaria/bank/spriteSheet.png");
		buildings.insert({ "bank",
			Building(&t[0], &t[1], &t[2], sf::Vector2u(2,1), npcAnimSpeed, false) });
		// bar

		t[3].loadFromFile("assets/building/bar/outside.png");
		t[4].loadFromFile("assets/building/bar/inside.png");
		t[5].loadFromFile("assets/npc/bulgaria/hotel/spriteSheet.png");
		buildings.insert({ "bar",
			Building(&t[3], &t[4], &t[5], sf::Vector2u(2,1), npcAnimSpeed, false) });


		// restaurant

		t[6].loadFromFile("assets/building/restaurant/outside.png");
		t[7].loadFromFile("assets/building/restaurant/inside.png");
		t[8].loadFromFile("assets/npc/bulgaria/restaurant/spriteSheet.png");
		buildings.insert({ "restaurant",
			Building(&t[6], &t[7], &t[8], sf::Vector2u(2,1), npcAnimSpeed, true) });
	}
	else if (country == "sp") // spain
	{
		// bank

		t[0].loadFromFile("assets/building/bank/outside.png");
		t[1].loadFromFile("assets/building/bank/inside.png");
		t[2].loadFromFile("assets/npc/spain/bank/spriteSheet.png");
		buildings.insert({ "bank",
			Building(&t[0], &t[1], &t[2], sf::Vector2u(2,1), npcAnimSpeed, false) });
		// bar

		t[3].loadFromFile("assets/building/bar/outside.png");
		t[4].loadFromFile("assets/building/bar/inside.png");
		t[5].loadFromFile("assets/npc/spain/hotel/spriteSheet.png");
		buildings.insert({ "bar",
			Building(&t[3], &t[4], &t[5], sf::Vector2u(2,1), npcAnimSpeed, false) });


		// restaurant

		t[6].loadFromFile("assets/building/restaurant/outside.png");
		t[7].loadFromFile("assets/building/restaurant/inside.png");
		t[8].loadFromFile("assets/npc/spain/restaurant/spriteSheet.png");
		buildings.insert({ "restaurant",
			Building(&t[6], &t[7], &t[8], sf::Vector2u(2,1), npcAnimSpeed, true) });
	}
	else // poland
	{
		// bank

		t[0].loadFromFile("assets/building/bank/outside.png");
		t[1].loadFromFile("assets/building/bank/inside.png");
		t[2].loadFromFile("assets/npc/poland/bank/spriteSheet.png");
		buildings.insert({ "bank",
			Building(&t[0], &t[1], &t[2], sf::Vector2u(2,1), npcAnimSpeed, false) });
		// bar

		t[3].loadFromFile("assets/building/bar/outside.png");
		t[4].loadFromFile("assets/building/bar/inside.png");
		t[5].loadFromFile("assets/npc/poland/hotel/spriteSheet.png");
		buildings.insert({ "bar",
			Building(&t[3], &t[4], &t[5], sf::Vector2u(2,1), npcAnimSpeed, false) });
		

		// restaurant

		t[6].loadFromFile("assets/building/restaurant/outside.png");
		t[7].loadFromFile("assets/building/restaurant/inside.png");
		t[8].loadFromFile("assets/npc/poland/restaurant/spriteSheet.png");
		buildings.insert({ "restaurant",
			Building(&t[6], &t[7], &t[8], sf::Vector2u(2,1), npcAnimSpeed, true) });
	}

	randomizeBuildingPos();
	
	setBuildingDoor("bank");
	setBuildingDoor("bar");
	setBuildingDoor("restaurant");
}

Country::~Country()
{

}

const Building Country::getBuilding(std::string building)
{
	if (buildings.find(building) != buildings.end())
		return buildings.at(building);
	return Building();
}

std::unordered_map<std::string, Building> Country::getBuildings()
{
	return buildings;
}

void Country::setBuildings(std::unordered_map<std::string, Building>& buildings)
{
	this->buildings = buildings;
}

void Country::setBuildingsInPos(float y)
{
	int i = 2;
	for (auto& j : buildings)
	{
		j.second.setInsidePos(sf::Vector2f(0, y * i));
		// set npc pos in different buildings
		if(j.first == "bar")
			j.second.setNPCPos(sf::Vector2f(WIDTH - j.second.getNPC().getRect().getSize().x, HEIGHT + y * i - j.second.getNPC().getRect().getSize().y - HEIGHT / 16.f));
		else if (j.first == "bank")
			j.second.setNPCPos(sf::Vector2f(WIDTH - j.second.getNPC().getRect().getSize().x, HEIGHT + y * i - j.second.getNPC().getRect().getSize().y - HEIGHT / 16.f));
		else if (j.first == "restaurant")
			j.second.setNPCPos(sf::Vector2f(WIDTH - j.second.getNPC().getRect().getSize().x, HEIGHT + y * i - j.second.getNPC().getRect().getSize().y - HEIGHT / 16.f));
		else if (j.first == "hotel")
			j.second.setNPCPos(sf::Vector2f(WIDTH - j.second.getNPC().getRect().getSize().x, HEIGHT + y * i - j.second.getNPC().getRect().getSize().y - HEIGHT / 16.f));
		else
			j.second.setNPCPos(sf::Vector2f(WIDTH - j.second.getNPC().getRect().getSize().x, HEIGHT + y * i - j.second.getNPC().getRect().getSize().y - HEIGHT / 16.f));
		i+=2;
	}
}

void Country::setBuildings(std::unordered_map<std::string, Building> buildings)
{
	this->buildings = buildings;
}



void Country::randomizeBuildingPos()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis((double)WIDTH / 2, (double)WIDTH * mapSize - buildings.at("restaurant").getOutsideRect().getSize().x);
	bool clear = false;
	for (auto& i : buildings)
	{
		clear = false;
		while (!clear) {
			clear = true;
			i.second.setOutsidePos(sf::Vector2f((float)dis(gen), HEIGHT - i.second.getOutsideRect().getSize().y));
			for (auto& j : buildings)
			{
				if (i.second.getOutsideRect().getGlobalBounds().intersects(j.second.getOutsideRect().getGlobalBounds())
					&& i.first != j.first)
				{
					clear = false;
					break;
				}
			}
		}
	}
}

void Country::setBuildingDoor(std::string building)
{
	buildings.at(building).setDoor(
		sf::Vector2f(buildings.at(building).getOutsideRect().getPosition().x +
			4.172f * buildings.at(building).getOutsideRect().getSize().x / 10.344f, 0.f),
		sf::Vector2f(buildings.at(building).getOutsideRect().getPosition().x +
			6.172f * buildings.at(building).getOutsideRect().getSize().x / 10.344f, HEIGHT));
}