#include "Player.h"
#include "sideSwiper.h"

Player::Player() :
	body(sf::RectangleShape()), velocity(sf::Vector2f(0.f, 0.f)), mSpeed(5)
{
	body.setSize(sf::Vector2f(WIDTH / 10.159f, HEIGHT / 3.214f));
	body.setFillColor(sf::Color::Yellow);
}

Player::Player(sf::RectangleShape body) :
	body(body), velocity(sf::Vector2f(0.f, 0.f)), mSpeed(20) {}


void Player::checkColision()
{
	// left
	if (body.getPosition().x < 0)
		body.setPosition(sf::Vector2f(0, body.getPosition().y));
	// right
	else if (body.getPosition().x + body.getSize().x > WIDTH)
		body.setPosition(sf::Vector2f(WIDTH - body.getSize().x, body.getPosition().y));
	// top
	if(body.getPosition().y < 0)
		body.setPosition(sf::Vector2f(body.getPosition().x, 0));
	// bottom
	else if (body.getPosition().y + body.getSize().y > HEIGHT)
		body.setPosition(sf::Vector2f(body.getPosition().x, HEIGHT - body.getSize().y));
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		velocity.x -= mSpeed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		velocity.x += mSpeed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		velocity.y -= mSpeed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		velocity.y += mSpeed;

	body.move(velocity);
	velocity = sf::Vector2f(0.f, 0.f);
	checkColision();
}