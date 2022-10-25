#pragma once
#include <SFML/Graphics.hpp>
class Player
{
public:
	Player();
	Player(sf::RectangleShape body);

// member variables
public:
	sf::RectangleShape body;
private:
	sf::Vector2f velocity;
	float mSpeed;

// methods
public:
	void move();
private:
	void checkColision();
};

