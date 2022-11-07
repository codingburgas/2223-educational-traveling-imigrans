#pragma once
#include <SFML/Graphics.hpp>
#include "NPC.h"

class Building
{

public:

	// constructors

	Building();
	Building(sf::RectangleShape outside, sf::RectangleShape inside, NPC npc = NPC());
	Building(sf::Texture* outside, sf::Texture* inside, NPC npc = NPC());
	Building(sf::RectangleShape outside, sf::RectangleShape inside, sf::Texture* outTexture, sf::Texture* inTexture, NPC npc = NPC());

	// getters
	const sf::RectangleShape getOutsideRect();
	const sf::RectangleShape getInsideRect();

	const sf::Texture* getOutsideTexture();
	const sf::Texture* getInsideTexture();

	const NPC getNPC();

	// setters

	void setOutsideRect(sf::RectangleShape& rect);
	void setInsideRect(sf::RectangleShape& rect);

	void setOutsideColor(sf::Color col);
	void setInsideColor(sf::Color col);

	void setOutsidePos(sf::Vector2f pos);
	void setInsidePos(sf::Vector2f pos);

	void setOutsideTexture(sf::Texture* outTexture);
	void setInsideTexture(sf::Texture* inTexture);

	void setNPC(NPC npc);

private:

	sf::RectangleShape outside;
	sf::RectangleShape inside;

	sf::Texture* outTexture;
	sf::Texture* inTexture;

	NPC npc;
};

