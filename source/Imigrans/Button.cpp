#include "Button.h"
#include <SFML/Graphics.hpp>
Button::Button():Button()
{
}

Button::Button(sf::RectangleShape shape, sf::Vector2f size, sf::Texture texture, sf::Vector2f pos, sf::Vector2f mousePos, sf::FloatRect boundingBox, sf::FloatRect mouseboundingBox, bool isClicked)
{
	shape.setSize(size);
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


