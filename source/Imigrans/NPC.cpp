#include "NPC.h"
#include "sideSwiper.h"

// constructors

NPC::NPC() :
	body(sf::RectangleShape()), texture(nullptr)
{
	body.setSize(sf::Vector2f(WIDTH / 10.159f, HEIGHT / 3.214f));
	body.setFillColor(sf::Color::Green);
}

NPC::NPC(sf::RectangleShape body) :
	body(body), texture(nullptr)
{}

NPC::NPC(sf::Texture* texture) :
	body(sf::RectangleShape()), texture(texture)
{
	body.setSize(sf::Vector2f(WIDTH / 10.159f, HEIGHT / 3.214f));
	body.setTexture(texture);
}

NPC::NPC(sf::RectangleShape body, sf::Texture* texture) :
	body(body), texture(texture)
{
	body.setTexture(texture);
}

// getters

const sf::RectangleShape NPC::getRect()
{
	return body;
}

const sf::Texture* NPC::getTexture()
{
	return texture;
}

// setters

void NPC::setRect(sf::RectangleShape body)
{
	this->body = body;
}

void NPC::setTexture(sf::Texture* texture)
{
	this->texture = texture;
	body.setTexture(texture);
}