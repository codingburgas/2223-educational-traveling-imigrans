#include "main.h"

int startGame()
{
	float bWidth = (float)WIDTH / 4, bHeight = (float)HEIGHT / 4;
	sf::RectangleShape button(sf::Vector2f(bWidth, bHeight));

	button.setFillColor(sf::Color::Yellow);
	button.setPosition(sf::Vector2f((WIDTH - bWidth) / 2, (HEIGHT - bHeight) / 2));

	while (win.isOpen())
	{
		sf::Event e;
		while (win.pollEvent(e))
		{
			if (e.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return 0; // close
			if (e.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				return 1; // main menu
		}

		win.clear(sf::Color::Black);
		win.draw(button);
		win.display();
	}
	return 0;
}