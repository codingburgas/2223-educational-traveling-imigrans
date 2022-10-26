#include "sideSwiper.h"
#include "Player.h"


sf::Clock frameTime;
sf::Time dt;

sf::Texture playerTex;
//playerTex.loadFromFile(".png");
Player player(&playerTex, sf::Vector2u(3/*row*/, 3/*collumn*/), 0.3f, 2.0f);
int startGame()
{
	
	while (win.isOpen())
	{
		dt = frameTime.restart();
		
		sf::Event e;
		while (win.pollEvent(e))
		{
			if (e.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return 0; // close
		}
		player.update(); 
		win.clear(sf::Color::Black);
		win.draw(player.body);
		win.display();
	}
	return 0;
}