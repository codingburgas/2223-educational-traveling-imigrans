#include "main.h"
#include <cmath>

bool loaded = false;
sf::Texture loadingTex;
void loadingScreen()
{
	loaded = false;
	loadingTex.loadFromFile("assets/background/loading.png");
	sf::Sprite loading;
	loading.setScale(1,1.001);
	loading.setTexture(loadingTex);
	win.setActive(true);
		win.clear(sf::Color::White);
		win.draw(loading);
		win.display();
	win.setActive(false);
}