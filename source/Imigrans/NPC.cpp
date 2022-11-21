#include "NPC.h"
#include "sideSwiper.h"

// constructors

NPC::NPC() :
	body(sf::RectangleShape(sf::Vector2f(WIDTH / 10.159f, HEIGHT / 3.214f))), texture(nullptr), anim(Animation())
{
	body.setFillColor(sf::Color::Green);
}

NPC::NPC(sf::RectangleShape body) :
	body(body), texture(nullptr), anim(Animation())
{}

NPC::NPC(sf::Texture* texture, sf::Vector2u imgCount, float sTime) :
	body(sf::RectangleShape(sf::Vector2f(texture->getSize().x/(2 * 3.214f), texture->getSize().y / 3.214f))), texture(texture),
	anim(Animation(texture, imgCount, sTime))
{
	body.setTexture(texture);
}

NPC::NPC(sf::RectangleShape body, sf::Texture* texture, sf::Vector2u imgCount, float sTime) :
	body(body), texture(texture), anim(Animation(texture, imgCount, sTime))
{
	body.setTexture(texture);
}

// getters

sf::RectangleShape NPC::getRect() const 
{
	return body;
}

const sf::Texture* NPC::getTexture()
{
	return texture;
}

bool NPC::getQuestGiven() const
{
	return questGiven;
}

// setters

void NPC::setRect(sf::RectangleShape body)
{
	this->body = body;
}

void NPC::setPos(sf::Vector2f pos)
{
	body.setPosition(pos);
}

void NPC::setTexture(sf::Texture* texture)
{
	this->texture = texture;
	body.setTexture(texture);
}

void NPC::updateAnim()
{
	anim.update(0, (float)dt.asMilliseconds(), true);
	body.setTextureRect(anim.uvRect);
}

void NPC::setQuestGiven(bool b)
{
	questGiven = b;
}

// methods

bool NPC::closeEnough()
{
	return abs(player.getRect().getPosition().x - body.getPosition().x) <= WIDTH / 3.f;
}
