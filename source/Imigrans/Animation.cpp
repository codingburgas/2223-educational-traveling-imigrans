#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imgCount, float sTime)
{
	this->imgCount = imgCount;
	this->sTime = sTime;
	tTime = 0;
	currentImg.x = 0;

	uvRect.width = texture->getSize().x / float(imgCount.x);
	uvRect.height = texture->getSize().y / float(imgCount.y);

}



void Animation::Update(int row, float dTime, bool fRight)
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


