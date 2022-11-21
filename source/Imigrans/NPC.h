#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
class NPC
{
public:

	// constructurs

	NPC();
	NPC(sf::Texture* texture, sf::Vector2u imgCount, float sTime);
	NPC(sf::RectangleShape body);
	NPC(sf::RectangleShape body, sf::Texture* texture, sf::Vector2u imgCount, float sTime);

	// getters

	sf::RectangleShape getRect() const;
	const sf::Texture* getTexture();
	bool getQuestGiven() const;

	// setters

	void setRect(sf::RectangleShape body);
	void setPos(sf::Vector2f pos);
	void setTexture(sf::Texture* texture);
	void updateAnim();
	void setQuestGiven(bool b);

	// methods

	bool closeEnough();

private:

	sf::RectangleShape body;
	sf::Texture* texture;
	Animation anim;
	bool questGiven = false;
};