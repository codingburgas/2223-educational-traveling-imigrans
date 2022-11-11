#include "main.h"
#include <cmath>

bool loaded = false;
sf::Texture loadingTex;
void loadingScreen()
{
	sf::Clock timeElapsed;
	loaded = false;
	loadingTex.loadFromFile("assets/background/loading.png");
	sf::Sprite loading;
	loading.setScale(1,1.001);
	loading.setTexture(loadingTex);
	win.setActive(true); // set window as an OpenGL render target
		win.clear(sf::Color::White);
		win.draw(loading);
		win.display();
	win.setActive(false);
	while (true)
	{
		if (loaded) // wait for loaded to be set to true
		{
			std::cout << "Loading took: " << timeElapsed.getElapsedTime().asMilliseconds() << "ms\n";
			return; // exit the thread
		}
	}
}