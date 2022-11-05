#pragma once
#include <SFML/Graphics.hpp>
#include"Animation.h"

class Player
{
public: // constructors
	Player();
	Player(sf::RectangleShape body);
	Player(sf::Texture* texture, sf::Vector2u imgCount, float sTime, float mSpeed);

	void update();

	// getters
	
	const sf::RectangleShape getRect();
	const sf::Texture* getTexture();
	const sf::View getView();

	// setters

	void setRect(sf::RectangleShape& rect);
	void setPosition(sf::Vector2f pos);
	void setTexture(sf::Texture* texture);
	void setView(sf::View view);
	void setViewSize(sf::Vector2f size);
	void setViewCenter(sf::Vector2f center);

private: 

	// methods
	void move();
	void checkColision();

	// members
	sf::RectangleShape body;
	sf::Texture *texture;
	sf::View follow;

	sf::Vector2f velocity;
	Animation animation;
	unsigned int row;
	float mSpeed;
	bool fRight;
	bool inside;
};

