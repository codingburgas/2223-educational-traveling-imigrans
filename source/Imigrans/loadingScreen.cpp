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
	sf::RectangleShape loading(sf::Vector2f((float)WIDTH, (float)HEIGHT + 1.f));
	loading.setTexture(&loadingTex);
	Animation loadingAnimation(&loadingTex, sf::Vector2u(3, 1), 0.01f); 

	sf::Clock deltaTime;
	while (true)
	{
		timeElapsed += deltaTime.restart().asMilliseconds();
		if (loaded) // wait for loaded to be set to true
		{

			std::cout << "\nLoading took: " << timeElapsed << "ms\n";
			return; // exit the thread


		}
		std::cout << " "; //mc Hammer says can't touch this
		loadingAnimation.update(0, deltaTime.getElapsedTime().asSeconds(), true);
		loading.setTextureRect(loadingAnimation.uvRect);
		win.setActive(true); // set window as an OpenGL render target
		win.clear(sf::Color::White);
		win.draw(loading);
		win.display();
		win.setActive(false);
	}
	
}