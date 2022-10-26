

#pragma once
#include <SFML/Graphics.hpp>


class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imgCount, float sTime);


	void Update(int row, float dTime, bool fRight);

public:

	sf::IntRect uvRect;

private:
	sf::Vector2u imgCount;//how many images
	sf::Vector2u currentImg;//get the current image

	float tTime;
	float sTime;
};

