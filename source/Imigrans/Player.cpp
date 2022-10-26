#include "Player.h"
#include "sideSwiper.h"

Player::Player(sf::Texture* texture, sf::Vector2u imgCount, float sTime, float mSpeed) :
	animation(texture, imgCount, sTime)
{
	this->mSpeed = mSpeed;
	row = 0;
	fRight = true;

	body.setSize(sf::Vector2f(100.0f, 150.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(206.f, 206.f);
	body.setTexture(texture);
};

void Player::checkColision()
{
	// left
	if (body.getPosition().x < 0)
		body.setPosition(sf::Vector2f(1, body.getPosition().y));
	// right
	else if (body.getPosition().x + body.getSize().x > WIDTH)
		body.setPosition(sf::Vector2f(WIDTH - body.getSize().x, body.getPosition().y));
	// top
	if (body.getPosition().y < 0)
		body.setPosition(sf::Vector2f(body.getPosition().x, 0 + 1));
	// bottom
	else if (body.getPosition().y + body.getSize().y > HEIGHT)
		body.setPosition(sf::Vector2f(body.getPosition().x, HEIGHT - body.getSize().y));
}

void Player::Update(float dTime)
{
	sf::Vector2f velocity(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		velocity.x -= mSpeed * dTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		velocity.x += mSpeed * dTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		velocity.y -= mSpeed * dTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		velocity.y += mSpeed * dTime;

	if (velocity.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;

		if (velocity.x > 0)
		{
			fRight = 1;
		}
		else
		{
			fRight = 0;

		}
	}
	animation.Update(row, dTime, fRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity);
	velocity = sf::Vector2f(0.f, 0.f);
	checkColision();
	
}
