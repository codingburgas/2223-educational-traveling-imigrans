#include "Animation.h"


Animation::Animation() :
	uvRect(sf::IntRect()), imgCount(sf::Vector2u()), currentImg(sf::Vector2u()), tTime(0), sTime(0)
{}

Animation::Animation(sf::Texture* texture) :
	uvRect(sf::IntRect()), imgCount(sf::Vector2u()), currentImg(sf::Vector2u()), tTime(0), sTime(0)
{
	currentImg.x = 0;

	uvRect.width = texture->getSize().x / imgCount.x;
	uvRect.height = texture->getSize().y / imgCount.y;
}

Animation::Animation(sf::Texture* texture, sf::Vector2u imgCount, float sTime) :
	uvRect(sf::IntRect()), imgCount(imgCount), currentImg(sf::Vector2u()), tTime(0), sTime(sTime)
{
	currentImg.x = 0;

	uvRect.width = texture->getSize().x / imgCount.x;
	uvRect.height = texture->getSize().y / imgCount.y;
}



void Animation::update(int row, float dTime, bool fRight)
{
	currentImg.y = row;
	tTime += dTime;

	if (tTime >= sTime)
	{
		tTime -= sTime; //makes animation smoother 
		currentImg.x++;

		if (currentImg.x++ >= imgCount.x)
		{
			currentImg.x = 0;
		}
	}

	uvRect.top = currentImg.y * uvRect.height;

	if (fRight) {
		uvRect.left = currentImg.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else {
		uvRect.left = (currentImg.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}

}


void Animation::setTexture(sf::Texture* texture)
{
	currentImg.x = 0;

	uvRect.width = texture->getSize().x / imgCount.x;
	uvRect.height = texture->getSize().y / imgCount.y;
}