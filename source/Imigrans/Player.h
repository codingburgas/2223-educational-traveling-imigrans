#pragma once
#include <SFML/Graphics.hpp>
#include"Animation.h"
class Player
{
public: //constructors
	Player();
	Player(sf::RectangleShape body);
	Player(sf::Texture* texture, sf::Vector2u imgCount, float sTime, float mSpeed);

public: // public members
	sf::RectangleShape body;
	sf::Texture texture;
private: // private members
	sf::Vector2f velocity;
	Animation animation;
	unsigned int row;
	float mSpeed;
	bool fRight;

public: // public methods
	void update();

private: // private methods
	void move();
	void checkColision();
};

