#include "Player.h"
#include "sideSwiper.h"


Player::Player() : 
	body(sf::RectangleShape()), texture(nullptr), velocity(sf::Vector2f(0.f, 0.f)), animation(),
	row(0), mSpeed(500), fRight(true)
{
	body.setSize(sf::Vector2f(WIDTH / 10.159f, HEIGHT / 3.214f));
	body.setFillColor(sf::Color::Green);

	follow.setCenter(sf::Vector2f(body.getSize().x / 2, body.getSize().y / 2));
	follow.setSize(sf::Vector2f(WIDTH, HEIGHT));
}

Player::Player(sf::RectangleShape body) :
	body(body), texture(nullptr), velocity(sf::Vector2f(0.f, 0.f)), animation(),
	row(0), mSpeed(500), fRight(true) 
{
	follow.setCenter(sf::Vector2f(body.getSize().x / 2, body.getSize().y / 2));
	follow.setSize(sf::Vector2f(WIDTH, HEIGHT));
}

Player::Player(sf::Texture* texture, sf::Vector2u imgCount, float sTime, float mSpeed) :
	body(sf::RectangleShape()), texture(texture), velocity(sf::Vector2f()), animation(texture, imgCount, sTime),
	row(0), mSpeed(500), fRight(true)
{
	body.setSize(sf::Vector2f(WIDTH / 10.159f, HEIGHT / 3.214f));
	body.setFillColor(sf::Color::Green);

	follow.setCenter(sf::Vector2f(body.getPosition().x + body.getSize().x / 2,
								  body.getPosition().y - body.getSize().y / 3));
	follow.setSize(sf::Vector2f(WIDTH, HEIGHT));
}

void Player::checkColision()
{
	// left
	if (body.getPosition().x < 0)
		body.setPosition(sf::Vector2f(1, body.getPosition().y));
	// right
	else if (body.getPosition().x + body.getSize().x > WIDTH * 3)
		body.setPosition(sf::Vector2f(WIDTH*3 - body.getSize().x, body.getPosition().y));
	// top
	if (body.getPosition().y < 0)
		body.setPosition(sf::Vector2f(body.getPosition().x, 0 + 1));
	// bottom
	else if (body.getPosition().y + body.getSize().y > HEIGHT)
		body.setPosition(sf::Vector2f(body.getPosition().x, HEIGHT - body.getSize().y));
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		velocity.x -= mSpeed * dt.asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		velocity.x += mSpeed * dt.asSeconds();

	// animation stuff
	if (velocity.x == 0.0f)
		row = 0;
	else
	{
		row = 1;

		if (velocity.x > 0)
			fRight = 1;
		else
			fRight = 0;
	}
	body.move(velocity);
	checkColision();
}

void Player::update()
{
	// update animation
	move();
	animation.update(row, (float)dt.asSeconds(), fRight);
	velocity = sf::Vector2f(0.f, 0.f);
	body.setTextureRect(animation.uvRect);
}

// getters

const sf::RectangleShape Player::getRect()
{
	return body;
}

const sf::Texture* Player::getTexture()
{
	return texture;
}

const sf::View Player::getView()
{
	return follow;
}

// setters

// rect
void Player::setRect(sf::RectangleShape& rect)
{
	body = rect;
}

void Player::setPosition(sf::Vector2f pos)
{
	body.setPosition(pos);
}

// texture
void Player::setTexture(sf::Texture* texture)
{
	this->texture = texture;
	body.setTexture(texture);
}

// view
void Player::setView(sf::View view)
{
	follow = view;
}

void Player::setViewSize(sf::Vector2f size)
{
	follow.setSize(size);
}

void Player::setViewCenter(sf::Vector2f center)
{
	follow.setCenter(center);
}