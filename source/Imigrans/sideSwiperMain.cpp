#include "sideSwiper.h"
#include "Player.h"

Player player;
sf::Clock dt;
int startGame()
{
	dt.restart();
	while (win.isOpen())
	{
		dt.restart();
		sf::Event e;
		while (win.pollEvent(e))
		{
			if (e.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return 0; // close
		}
		player.move();
		win.clear(sf::Color::Black);
		win.draw(player.body);
		win.display();
	}
	return 0;
}