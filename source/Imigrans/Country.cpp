#include "Country.h"
#include "sideSwiper.h"
#include <random>
Country::Country() :
	buildings(std::unordered_map<std::string, Building>())
{
}

sf::Texture t[6];
Country::Country(std::string country)
{
	
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
		buildings.insert({ "bank",
			Building(&t[0],&t[1]) });
		// bar

		t[2].loadFromFile("assets/building/bar/outside.png");
		t[3].loadFromFile("assets/building/bar/inside.png");
		buildings.insert({ "bar",
			Building(&t[2],&t[3]) });
		

		// restaurant

		t[4].loadFromFile("assets/building/bar/outside.png");
		t[5].loadFromFile("assets/building/bar/inside.png");
		buildings.insert({ "restaurant",
			Building(&t[4],&t[5]) });
		
	}
	else if (country == "it") // italy
	{
		// bank

		t[0].loadFromFile("assets/building/bar/outside.png");
		t[1].loadFromFile("assets/building/bank/inside.png");
		buildings.insert({ "bank",
			Building(&t[0],&t[1]) });

		// bar

		t[0].loadFromFile("assets/building/bar/outside.png");
		t[1].loadFromFile("assets/building/bar/inside.png");
		buildings.insert({ "bar",
			Building(&t[0],&t[1]) });

		// restaurant

		t[0].loadFromFile("assets/building/restaurant/outside.png");
		t[1].loadFromFile("assets/building/restaurant/inside.png");
		buildings.insert({ "restaurant",
			Building(&t[0],&t[1]) });
	}
	else if (country == "en") // england
	{
		// bank

		t[0].loadFromFile("assets/building/bank/outside.png");
		t[1].loadFromFile("assets/building/bank/inside.png");
		buildings.insert({ "bank",
			Building(&t[0],&t[1]) });

		// bar

		t[0].loadFromFile("assets/building/bar/outside.png");
		t[1].loadFromFile("assets/building/bar/inside.png");
		buildings.insert({ "bar",
			Building(&t[0],&t[1]) });

		// restaurant

		t[0].loadFromFile("assets/building/restaurant/outside.png");
		t[1].loadFromFile("assets/building/restaurant/inside.png");
		buildings.insert({ "restaurant",
			Building(&t[0],&t[1]) });
	}
	else if (country == "fr") // france
	{
		// bank

		t[0].loadFromFile("assets/building/bank/outside.png");
		t[1].loadFromFile("assets/building/bank/inside.png");
		buildings.insert({ "bank",
			Building(&t[0],&t[1]) });

		// bar

		t[0].loadFromFile("assets/building/bar/outside.png");
		t[1].loadFromFile("assets/building/bar/inside.png");
		buildings.insert({ "bar",
			Building(&t[0],&t[1]) });

		// restaurant

		t[0].loadFromFile("assets/building/restaurant/outside.png");
		t[1].loadFromFile("assets/building/restaurant/inside.png");
		buildings.insert({ "restaurant",
			Building(&t[0],&t[1]) });
	}
	else if (country == "rm") // romania
	{
		// bank

		t[0].loadFromFile("assets/building/bank/outside.png");
		t[1].loadFromFile("assets/building/bank/inside.png");
		buildings.insert({ "bank",
			Building(&t[0],&t[1]) });

		// bar

		t[0].loadFromFile("assets/building/bar/outside.png");
		t[1].loadFromFile("assets/building/bar/inside.png");
		buildings.insert({ "bar",
			Building(&t[0],&t[1]) });

		// restaurant

		t[0].loadFromFile("assets/building/restaurant/outside.png");
		t[1].loadFromFile("assets/building/restaurant/inside.png");
		buildings.insert({ "restaurant",
			Building(&t[0],&t[1]) });
	}
	else if (country == "bg") // bulgaria
	{
		// bank

		t[0].loadFromFile("assets/building/bank/outside.png");
		t[1].loadFromFile("assets/building/bank/inside.png");
		buildings.insert({ "bank",
			Building(&t[0],&t[1]) });

		// bar

		t[0].loadFromFile("assets/building/bar/outside.png");
		t[1].loadFromFile("assets/building/bar/inside.png");
		buildings.insert({ "bar",
			Building(&t[0],&t[1]) });

		// restaurant

		t[0].loadFromFile("assets/building/restaurant/outside.png");
		t[1].loadFromFile("assets/building/restaurant/inside.png");
		buildings.insert({ "restaurant",
			Building(&t[0],&t[1]) });
	}
	else if (country == "sp") // Spain
	{
		// bank

		t[0].loadFromFile("assets/building/bar/outside.png");
		t[1].loadFromFile("assets/building/bar/inside.png");
		buildings.insert({ "bank",
			Building(&t[0],&t[1]) });

		// bar

		t[2].loadFromFile("assets/building/bar/outside.png");
		t[3].loadFromFile("assets/building/bar/inside.png");
		buildings.insert({ "bar",
			Building(&t[2],&t[3]) });

		// restaurant

		t[4].loadFromFile("assets/building/bank/outside.png");
		t[5].loadFromFile("assets/building/bank/inside.png");
		buildings.insert({ "restaurant",
			Building(&t[4],&t[5]) });
	}
	else // poland
	{
		// bank

		t[0].loadFromFile("assets/building/bar/outside.png");
		t[1].loadFromFile("assets/building/bar/inside.png");
		buildings.insert({ "bank",
			Building(&t[0],&t[1]) });

		// bar

		t[2].loadFromFile("assets/building/bar/outside.png");
		t[3].loadFromFile("assets/building/bar/inside.png");
		buildings.insert({ "bar",
			Building(&t[2],&t[3]) });

		// restaurant

		t[4].loadFromFile("assets/building/bank/outside.png");
		t[5].loadFromFile("assets/building/bank/inside.png");
		buildings.insert({ "restaurant",
			Building(&t[4],&t[5]) });
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

const std::unordered_map<std::string, Building> Country::getBuildings()
{
	return buildings;
}

void Country::setBuildings(std::unordered_map<std::string, Building>& buildings)
{
	this->buildings = buildings;
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
			i.second.setOutsidePos(sf::Vector2f(dis(gen), HEIGHT - i.second.getOutsideRect().getSize().y));
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
			4.172f * buildings.at(building).getOutsideRect().getSize().x / 10.344, 0),
		sf::Vector2f(buildings.at(building).getOutsideRect().getPosition().x +
			6.172f * buildings.at(building).getOutsideRect().getSize().x / 10.344, HEIGHT));
}