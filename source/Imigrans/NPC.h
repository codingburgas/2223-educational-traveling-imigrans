#pragma once
#include <SFML/Graphics.hpp>

class NPC
{
public:
	NPC();
	NPC(sf::Texture* texture);
	NPC(sf::RectangleShape body,sf::Vector2f size());

public: 

	sf::RectangleShape body;
	sf::Vector2f size; 
	sf::Texture texture;

};

