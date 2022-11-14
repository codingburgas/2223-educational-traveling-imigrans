#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
class NPC
{
public:

	// constructurs

	NPC();
	NPC(sf::Texture* texture);
	NPC(sf::RectangleShape body);
	NPC(sf::RectangleShape body, sf::Texture* texture);

	~NPC();
	// getters

	const sf::RectangleShape getRect();
	const sf::Texture* getTexture();

	// setters

	void setRect(sf::RectangleShape body);
	void setTexture(sf::Texture* texture);

private:

	sf::RectangleShape body;
	sf::Texture* texture;
	Animation anim = Animation();
};