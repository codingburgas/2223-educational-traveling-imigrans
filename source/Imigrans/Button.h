#pragma once
#include <SFML/Graphics.hpp>
class Button

{

public:
	Button();
	Button(sf::RectangleShape shape,sf::Vector2f size,sf::Texture texture,sf::Vector2f pos, sf::Vector2f mousePos,sf::FloatRect boundingBox, sf::FloatRect mouseboundingBox, bool isClicked);


public:

	sf::RectangleShape shape;
	
	sf::Vector2f size;

	sf::Texture texture;
	
	sf::Vector2f position;

	sf::Vector2f mousePos;

	sf::FloatRect boundingBox;

	sf::FloatRect mouseboundingBox;
	
	bool isClicked = false;
};

