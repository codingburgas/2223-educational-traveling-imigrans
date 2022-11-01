#pragma once

#include <SFML/Graphics.hpp>
class Building

{
	
	public:
		Building();
		Building(sf::Texture* texture);
		Building(sf::RectangleShape front, sf::RectangleShape inside, sf::Vector2f frontSize(), sf::Texture texture, sf::Texture BgTexture);

	public:

		sf::RectangleShape front;
		sf::RectangleShape inside;
		sf::Vector2f size;

		sf::Texture texture; 
		sf::Texture BgTexture;


	


};

