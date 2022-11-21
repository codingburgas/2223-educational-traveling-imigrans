#pragma once
#include <SFML/Graphics.hpp>
#include "NPC.h"

class Building
{

public:

	// constructors

	Building();
	Building(sf::RectangleShape outside, sf::RectangleShape inside, NPC npc = NPC());
	Building(sf::Texture* outside, sf::Texture* inside, bool restaurant = false, NPC npc = NPC());
	Building(sf::Texture* outTexture, sf::Texture* inTexture, sf::Texture* npcTexture, sf::Vector2u npcImgCount, float npcSTime, bool restaurant = false);

	Building(sf::RectangleShape outside, sf::RectangleShape inside, sf::Texture* outTexture, sf::Texture* inTexture,  bool restaurant = false, NPC npc = NPC());
	Building(sf::RectangleShape outside, sf::RectangleShape inside, sf::Texture* outTexture, sf::Texture* inTexture, 
		sf::Texture* npcTexture, sf::Vector2u npcImgCount, float npcSTime, bool restaurant = false);

	// getters
	sf::RectangleShape getOutsideRect() const;
	sf::RectangleShape getInsideRect() const;

	sf::Texture* getOutsideTexture() const;
	sf::Texture* getInsideTexture() const;

	sf::Vector2f getDoorPos() const;

	NPC getNPC() const;

	// setters

	void setOutsideRect(sf::RectangleShape rect);
	void setInsideRect(sf::RectangleShape rect);

	void setOutsideColor(sf::Color col);
	void setInsideColor(sf::Color col);

	void setOutsidePos(sf::Vector2f pos);
	void setInsidePos(sf::Vector2f pos);

	void setOutsideTexture(sf::Texture* outTexture);
	void setInsideTexture(sf::Texture* inTexture);

	void setDoor(sf::Vector2f topLeft, sf::Vector2f bottomRight);

	void setNPC(NPC npc);
	void setNPCPos(sf::Vector2f pos);
	void setNPCQuestGiven(bool b);

	// methods

	bool intersectsDoor(const sf::RectangleShape& rect) const;
	void tpInside() const;
	void tpOutside(sf::Vector2f pos) const;
	void updateNPCAnim();

private:

	sf::RectangleShape outside;
	sf::RectangleShape inside;

	sf::Texture* outTexture;
	sf::Texture* inTexture;

	sf::Vector2f doorTopLeft, doorBottomRight;

	NPC npc;
};

