#include "sideSwiper.h"

int gameOver()
{
	sf::Font font;
	font.loadFromFile("assets/font/Teko-Bold.ttf");
	sf::Text gameover("Game Over!", font, 169);
	gameover.setOrigin(	gameover.getLocalBounds().left + gameover.getLocalBounds().width / 2,
						gameover.getLocalBounds().top + gameover.getLocalBounds().height / 2);
	gameover.setPosition(WIDTH / 2, HEIGHT / 3);
	sf::Text ending("", font, 72);
	sf::Text money("", font, 72);
	sf::Text pressSpace("Press Space to play again! Or press Escape to exit", font, 36);
	pressSpace.setOrigin(pressSpace.getLocalBounds().left + pressSpace.getLocalBounds().width / 2,
						 pressSpace.getLocalBounds().top + pressSpace.getLocalBounds().height / 2);
	pressSpace.setPosition(WIDTH / 2, HEIGHT / 1.25f);
	if (currencyCount < 0)
	{
		ending.setString("You Lost!");
		ending.setOrigin(ending.getLocalBounds().left + ending.getLocalBounds().width / 2,
			ending.getLocalBounds().top + ending.getLocalBounds().height / 2);
		ending.setPosition(WIDTH / 2, HEIGHT / 3 + HEIGHT / 10);

		money.setString("You owe " + std::to_string(abs(currencyCount)) + " olio");
		money.setOrigin(money.getLocalBounds().left + money.getLocalBounds().width / 2,
			money.getLocalBounds().top + money.getLocalBounds().height / 2);
		money.setPosition(WIDTH / 2, HEIGHT / 3 + HEIGHT / 6);

		while (true)
		{
			sf::Event e;
			while (win.pollEvent(e))
			{
				if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Space)
					return 7; // restart game
				if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
					exit(0);
			}
			win.clear(sf::Color(200, 0, 0));
			win.draw(gameover);
			win.draw(ending);
			win.draw(money);
			win.draw(pressSpace);
			win.display();
		}
	}
	ending.setString("You Won!");
	ending.setOrigin(ending.getLocalBounds().left + ending.getLocalBounds().width / 2,
		ending.getLocalBounds().top + ending.getLocalBounds().height / 2);
	ending.setPosition(WIDTH / 2, HEIGHT / 3 + HEIGHT / 10);

	money.setString("You earned " + std::to_string(abs(currencyCount)) + " olio");
	money.setOrigin(money.getLocalBounds().left + money.getLocalBounds().width / 2,
		money.getLocalBounds().top + money.getLocalBounds().height / 2);
	money.setPosition(WIDTH / 2, HEIGHT / 3 + HEIGHT / 6);
	while (true)
	{
		sf::Event e;
		while (win.pollEvent(e))
		{
			if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Space)
				return 7; // restart game
			if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
				exit(0);
		}
		win.clear(sf::Color(0, 200, 0));
		win.draw(gameover);
		win.draw(ending);
		win.draw(money);
		win.draw(pressSpace);
		win.display();
	}
}