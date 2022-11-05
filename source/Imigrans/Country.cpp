#include "Country.h"
#include "sideSwiper.h"
#include <random>
Country::Country() : 
	buildings(std::unordered_map<std::string,Building>())
{
}

sf::Texture t1, t2;
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

		t1.loadFromFile("assets/building/bank/outside.png");
		t2.loadFromFile("assets/building/bank/inside.png");
		buildings.insert({ "bank",
			Building(&t1,&t2)});

		// hotel

		t1.loadFromFile("assets/building/hotel/outside.png");
		t2.loadFromFile("assets/building/hotel/inside.png");
		buildings.insert({ "hotel",
			Building(&t1,&t2) });

		// restaurant

		t1.loadFromFile("assets/building/restaurant/outside.png");
		t2.loadFromFile("assets/building/restaurant/inside.png");
		buildings.insert({ "restaurant",
			Building(&t1,&t2) });
	}
	else if (country == "it") // italy
	{
		// bank

		t1.loadFromFile("assets/building/bank/outside.png");
		t2.loadFromFile("assets/building/bank/inside.png");
		buildings.insert({ "bank",
			Building(&t1,&t2) });

		// hotel

		t1.loadFromFile("assets/building/hotel/outside.png");
		t2.loadFromFile("assets/building/hotel/inside.png");
		buildings.insert({ "hotel",
			Building(&t1,&t2) });

		// restaurant

		t1.loadFromFile("assets/building/restaurant/outside.png");
		t2.loadFromFile("assets/building/restaurant/inside.png");
		buildings.insert({ "restaurant",
			Building(&t1,&t2) });
	}
	else if (country == "en") // england
	{
		// bank

		t1.loadFromFile("assets/building/bank/outside.png");
		t2.loadFromFile("assets/building/bank/inside.png");
		buildings.insert({ "bank",
			Building(&t1,&t2) });

		// hotel

		t1.loadFromFile("assets/building/hotel/outside.png");
		t2.loadFromFile("assets/building/hotel/inside.png");
		buildings.insert({ "hotel",
			Building(&t1,&t2) });

		// restaurant

		t1.loadFromFile("assets/building/restaurant/outside.png");
		t2.loadFromFile("assets/building/restaurant/inside.png");
		buildings.insert({ "restaurant",
			Building(&t1,&t2) });
	}
	else if (country == "fr") // france
	{
		// bank

		t1.loadFromFile("assets/building/bank/outside.png");
		t2.loadFromFile("assets/building/bank/inside.png");
		buildings.insert({ "bank",
			Building(&t1,&t2) });

		// hotel

		t1.loadFromFile("assets/building/hotel/outside.png");
		t2.loadFromFile("assets/building/hotel/inside.png");
		buildings.insert({ "hotel",
			Building(&t1,&t2) });

		// restaurant

		t1.loadFromFile("assets/building/restaurant/outside.png");
		t2.loadFromFile("assets/building/restaurant/inside.png");
		buildings.insert({ "restaurant",
			Building(&t1,&t2) });
	}
	else if (country == "rm") // romania
	{
		// bank

		t1.loadFromFile("assets/building/bank/outside.png");
		t2.loadFromFile("assets/building/bank/inside.png");
		buildings.insert({ "bank",
			Building(&t1,&t2) });

		// hotel

		t1.loadFromFile("assets/building/hotel/outside.png");
		t2.loadFromFile("assets/building/hotel/inside.png");
		buildings.insert({ "hotel",
			Building(&t1,&t2) });

		// restaurant

		t1.loadFromFile("assets/building/restaurant/outside.png");
		t2.loadFromFile("assets/building/restaurant/inside.png");
		buildings.insert({ "restaurant",
			Building(&t1,&t2) });
	}
	else if (country == "bg") // bulgaria
	{
		// bank

		t1.loadFromFile("assets/building/bank/outside.png");
		t2.loadFromFile("assets/building/bank/inside.png");
		buildings.insert({ "bank",
			Building(&t1,&t2) });

		// hotel

		t1.loadFromFile("assets/building/hotel/outside.png");
		t2.loadFromFile("assets/building/hotel/inside.png");
		buildings.insert({ "hotel",
			Building(&t1,&t2) });

		// restaurant

		t1.loadFromFile("assets/building/restaurant/outside.png");
		t2.loadFromFile("assets/building/restaurant/inside.png");
		buildings.insert({ "restaurant",
			Building(&t1,&t2) });
	}
	else if (country == "sp") // Spain
	{
		// bank

		t1.loadFromFile("assets/building/bank/outside.png");
		t2.loadFromFile("assets/building/bank/inside.png");
		buildings.insert({ "bank",
			Building(&t1,&t2) });

		// hotel

		t1.loadFromFile("assets/building/hotel/outside.png");
		t2.loadFromFile("assets/building/hotel/inside.png");
		buildings.insert({ "hotel",
			Building(&t1,&t2) });

		// restaurant

		t1.loadFromFile("assets/building/restaurant/outside.png");
		t2.loadFromFile("assets/building/restaurant/inside.png");
		buildings.insert({ "restaurant",
			Building(&t1,&t2) });
	}
	else // poland
	{
		// bank

		t1.loadFromFile("assets/building/bank/outside.png");
		t2.loadFromFile("assets/building/bank/inside.png");
		buildings.insert({ "bank",
			Building(&t1,&t2) });

		// hotel

		t1.loadFromFile("assets/building/hotel/outside.png");
		t2.loadFromFile("assets/building/hotel/inside.png");
		buildings.insert({ "hotel",
			Building(&t1,&t2) });

		// restaurant

		t1.loadFromFile("assets/building/restaurant/outside.png");
		t2.loadFromFile("assets/building/restaurant/inside.png");
		buildings.insert({ "restaurant",
			Building(&t1,&t2) });
	}
	buildings["bank"].setOutsideColor(sf::Color::Yellow);
	buildings["hotel"].setOutsideColor(sf::Color::Cyan);
	buildings["restaurant"].setOutsideColor(sf::Color::Red);
	randomizeBuildingPos();
}

const Building Country::getBuilding(std::string building)
{
	if(buildings.find(building) != buildings.end())
		return buildings.at(building);
	return Building();
}

const std::unordered_map<std::string, Building> Country::getBuildings()
{
	return buildings;
}

void Country::setBuildings(std::unordered_map<std::string, Building> &buildings)
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
	std::uniform_real_distribution<> dis((double)WIDTH/2, (double)WIDTH * mapSize - buildings.at("restaurant").getOutsideRect().getSize().x);
	bool clear = false;
	for (auto &i : buildings)
	{
		clear = false;
		while (!clear) {
			clear = true;
			i.second.setOutsidePos(sf::Vector2f(dis(gen), HEIGHT - i.second.getOutsideRect().getSize().y));
			for (auto &j : buildings)
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
