#include "Button.h"
#include <SFML/Graphics.hpp>
Button::Button():Button()
{
}

Button::Button(sf::RectangleShape shape, sf::Vector2f size, sf::Texture texture, sf::Vector2f pos, sf::Vector2f mousePos, sf::FloatRect boundingBox, sf::FloatRect mouseboundingBox, bool isClicked,sf::Color color)
{
	shape.setSize(size);
	shape.setFillColor(color);
	shape.setTexture(&texture);
	shape.setPosition(pos);

	if (boundingBox.intersects(mouseboundingBox) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		isClicked = true; 
	}
	else
	{
		isClicked = false;
	}


	
}


