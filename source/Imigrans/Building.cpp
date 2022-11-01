#include "Building.h"
#include "main.h"
#include <SFML/Graphics.hpp>
#include "NPC.h"

Building::Building()
{
}

Building::Building(sf::Texture* texture)
{

}

Building::Building(sf::RectangleShape outside, sf::RectangleShape inside, sf::Vector2f frontSize(), sf::Texture outsideTexture, sf::Texture insideTexture)
{

	outside.setTexture(&outsideTexture);
	inside.setTexture(&insideTexture);

}

