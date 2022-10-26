#include "sideSwiper.h"
#include "Player.h"


sf::Clock frameTime;
sf::Time dt;
sf::Texture playerTex;

//playerTex.loadFromFile(".png");
Player player(&playerTex, sf::Vector2u(3/*row*/, 3/*collumn*/), 0.3f, 2.0f);

int startGame()
{
	sf::RectangleShape background(sf::Vector2f(WIDTH,HEIGHT));
	background.setFillColor(sf::Color::White);
	player.body.setPosition(sf::Vector2f(player.body.getPosition().x, HEIGHT - player.body.getSize().y));
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
		win.setView(player.follow);
		player.follow.setCenter(sf::Vector2f(player.body.getPosition().x + player.body.getSize().x/2,
											 player.body.getPosition().y - player.body.getSize().y/3));
		win.draw(background);
		win.draw(player.body);
		win.display();
	}
	return 0;
}