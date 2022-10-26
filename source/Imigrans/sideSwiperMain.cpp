#include "sideSwiper.h"
#include "Player.h"

sf::Texture playerTex;
//playerTex.loadFromFile(".png");
Player player(&playerTex, sf::Vector2u(3/*row*/, 3/*collumn*/), 0.3, 2.0f);
sf::Clock dt;
int startGame()
{
	dt.restart();
	float dTime;
	while (win.isOpen())
	{
		dTime = dt.restart().asMilliseconds();
		dt.restart();
		sf::Event e;
		while (win.pollEvent(e))
		{
			if (e.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return 0; // close
		}
		player.Update(dTime); 
		win.clear(sf::Color::Black);
		win.draw(player.body);
		win.display();
	}
	return 0;
}