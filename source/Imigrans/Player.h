#pragma once
#include <SFML/Graphics.hpp>
#include"Animation.h"
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imgCount, float sTime, float mSpeed);

	void Update(float dTime);

	sf::RectangleShape body;



private:

	Animation animation;
	unsigned int row;
	float mSpeed;
	bool fRight;

public:
	void move();
private:
	void checkColision();
};

