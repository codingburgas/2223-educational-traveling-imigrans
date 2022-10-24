#include "main.h"

sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "Imigrans", sf::Style::Fullscreen);

int manageScreen(std::function<int()> func)
{
	switch (func())
	{
	
	case 0: // close
		win.close();
		exit(0);
		break;
	case 1: // open main menu
		manageScreen(mainMenu);
		break;
	case 2: // start game
		manageScreen(startGame);
		break;
	default: // error
		std::cout << "Error Wrong return value at " << &func << "\n";
	}
	return 0;
}