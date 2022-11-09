

#pragma once
#include <SFML/Graphics.hpp>


class Animation
{
public:
	Animation();
	Animation(sf::Texture* texture);
	Animation(sf::Texture* texture, sf::Vector2u imgCount, float sTime);


	void update(int row, float dTime, bool fRight);

	void setTexture(sf::Texture* texture);


public:

	sf::IntRect uvRect;

private:
	sf::Vector2u imgCount;
	sf::Vector2u currentImg;
	bool aforward = true;
	float tTime;
	float sTime;
	
};

