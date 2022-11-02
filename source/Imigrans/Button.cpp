#include "Button.h"
#include "sideSwiper.h"

// constructors

Button::Button() :
	rect(sf::RectangleShape(sf::Vector2f(WIDTH / 15.f, HEIGHT / 15.f))), texture(nullptr), clicked(false)
{
	rect.setFillColor(sf::Color::Green);
}

Button::Button(sf::RectangleShape rect, sf::Texture* texture) : 
	rect(rect), texture(texture), clicked(false)
{
	rect.setTexture(texture);
}

// getters

const sf::RectangleShape Button::getRect()
{
	return rect;
}

const sf::Texture* Button::getTexture()
{
	return texture;
}

const bool Button::isClicked()
{
	return clicked;
}

// setters

void Button::setRect(sf::RectangleShape& rect)
{
	this->rect = rect;
}

void Button::setTexture(sf::Texture* texture)
{
	this->texture = texture;
	rect.setTexture(texture);
}

void Button::setClicked(bool clicked)
{
	this->clicked = clicked;
}