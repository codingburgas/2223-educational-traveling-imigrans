#include "Building.h"
#include "sideSwiper.h"

// constructors

Building::Building() :
	outside(sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT))),
	inside(sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT))),
	outTexture(nullptr), inTexture(nullptr), doorTopLeft(0, 0), doorBottomRight(0, 0),
	npc(NPC())
{
}

Building::Building(sf::RectangleShape outside, sf::RectangleShape inside, NPC npc) :
	outside(outside), inside(inside), outTexture(nullptr), inTexture(nullptr),
	doorTopLeft(0, 0), doorBottomRight(0, 0),
	npc(npc)
{
}

Building::Building(sf::Texture* outside, sf::Texture* inside, bool restaurant, NPC npc) :
	outside(sf::RectangleShape(sf::Vector2f(WIDTH / 2.f, HEIGHT / 1.2f))), inside(sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT))),
	outTexture(outside), inTexture(inside), doorTopLeft(0, 0), doorBottomRight(0, 0),
	npc(npc)
{
	if (restaurant) this->outside.setSize(sf::Vector2f(WIDTH, HEIGHT / 1.2f));
	this->outside.setTexture(outside);
	this->inside.setTexture(inside);
}

Building::Building(sf::RectangleShape outside, sf::RectangleShape inside, sf::Texture* outTexture, sf::Texture* inTexture, bool restaurant, NPC npc) :
	outside(outside), inside(inside), outTexture(outTexture), inTexture(inTexture),
	doorTopLeft(0, 0), doorBottomRight(0, 0),
	npc(npc)
{
	if (restaurant) this->outside.setSize(sf::Vector2f(WIDTH, HEIGHT / 1.2f));
	outside.setTexture(outTexture);
	inside.setTexture(inTexture);
}

Building::~Building()
{
	//delete outTexture;
	//delete inTexture;
	//npc.~NPC();
}

// getters

const sf::RectangleShape Building::getOutsideRect()
{
	return outside;
}

const sf::RectangleShape Building::getInsideRect()
{
	return inside;
}

const sf::Texture* Building::getOutsideTexture()
{
	return outTexture;
}

const sf::Texture* Building::getInsideTexture()
{
	return inTexture;
}

const sf::Vector2f Building::getDoorPos()
{
	return doorTopLeft;
}

const NPC Building::getNPC()
{
	return npc;
}

// setters 

void Building::setOutsideRect(sf::RectangleShape rect)
{
	outside = rect;
}

void Building::setInsideRect(sf::RectangleShape rect)
{
	inside = rect;
}

void Building::setOutsideColor(sf::Color col)
{
	outside.setFillColor(col);
}

void Building::setInsideColor(sf::Color col)
{
	inside.setFillColor(col);
}

void Building::setOutsidePos(sf::Vector2f pos)
{
	outside.setPosition(pos);
}

void Building::setInsidePos(sf::Vector2f pos)
{
	inside.setPosition(pos);
}

void Building::setOutsideTexture(sf::Texture* texture)
{
	outTexture = texture;
	outside.setTexture(texture);
}

void Building::setInsideTexture(sf::Texture* texture)
{
	inTexture = texture;
	inside.setTexture(texture);
}

void Building::setDoor(sf::Vector2f topLeft, sf::Vector2f bottomRight)
{
	doorTopLeft = topLeft;
	doorBottomRight = bottomRight;
}

void Building::setNPC(NPC npc)
{
	this->npc = npc;
}

// methods

bool Building::intersectsDoor(const sf::RectangleShape& rect)
{
	return rect.getGlobalBounds().intersects(sf::FloatRect(doorTopLeft.x, doorTopLeft.y, doorBottomRight.x - doorTopLeft.x, doorBottomRight.y - doorTopLeft.y));
}

void Building::tpInside()
{
	player.setPosition(sf::Vector2f(0, inside.getPosition().y + HEIGHT - player.getRect().getSize().y - HEIGHT / 16.f));
	player.setInside(true);
}

void Building::tpOutside(sf::Vector2f pos)
{
	player.setInside(false);
	player.setPosition(pos);
}
