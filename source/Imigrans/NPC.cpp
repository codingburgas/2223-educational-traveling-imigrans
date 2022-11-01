#include "NPC.h"
#include "main.h"
#include <SFML/Graphics.hpp>

NPC::NPC() :
	body(sf::RectangleShape())
{
	body.setSize(sf::Vector2f(WIDTH / 10.159f, HEIGHT / 3.214f));
	body.setFillColor(sf::Color::Green);

	
}

NPC::NPC(sf::RectangleShape body,sf::Vector2f()) :
	body(body),size(size)
{
	
}

NPC::NPC(sf::Texture* texture) :
	body(sf::RectangleShape())
{
	body.setSize(sf::Vector2f(WIDTH / 10.159f, HEIGHT / 3.214f));
	body.setFillColor(sf::Color::Green);

	
	
}