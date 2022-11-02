#pragma once
#include <SFML/Graphics.hpp>
class Button
{

public:
	// constructors

	Button();
	Button(sf::RectangleShape rect,sf::Texture* texture);

	// getters
	
	const sf::RectangleShape getRect();
	const sf::Texture* getTexture();
	const bool isClicked();

	// setters

	void setRect(sf::RectangleShape& rect);
	void setTexture(sf::Texture* texture);
	void setClicked(bool clicked);
private:

	sf::RectangleShape rect;
	sf::Texture* texture;
	
	bool clicked;
};

