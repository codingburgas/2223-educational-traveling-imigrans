#include "main.h"

sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "Imigrans", sf::Style::Fullscreen);


int main()
{
	if (!mainMenu())
		win.close();
}