#include "main.h"
#include <cmath>
#include"Animation.h"

bool loaded = false;
sf::Texture loadingTex;
void loadingScreen()
{
	int timeElapsed = 0;
	loaded = false;
	loadingTex.loadFromFile("assets/background/loadingSpriteSheet.png");
	sf::RectangleShape loading(sf::Vector2f(WIDTH, HEIGHT + 1.f));
	loading.setTexture(&loadingTex);
	Animation loadingAnimation(&loadingTex, sf::Vector2u(3, 1), 0.0001f); // ne baray nulite

	sf::Clock deltaTime;
	while (true)
	{
		timeElapsed += deltaTime.restart().asMilliseconds();
		if (loaded) // wait for loaded to be set to true
		{
			std::cout << "\nLoading took: " << timeElapsed << "ms\n";
			return; // exit the thread
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			exit(0);// close

		loadingAnimation.update(0, deltaTime.getElapsedTime().asSeconds(), true);
		loading.setTextureRect(loadingAnimation.uvRect);
		win.setActive(true); // set window as an OpenGL render target
		win.clear(sf::Color::White);
		win.draw(loading);
		win.display();
		win.setActive(false);
	}
}