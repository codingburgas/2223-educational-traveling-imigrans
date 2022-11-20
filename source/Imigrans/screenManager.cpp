#include "main.h"

sf::RenderWindow win(sf::VideoMode((unsigned)WIDTH, (unsigned)HEIGHT), "Imigrans", sf::Style::None);

int manageScreen(std::function<int()> func)
{
	switch (func())
	{
	
	case 0: // close
		win.close();
		exit(0);
		break;
	case 2: // start game
		manageScreen(startGame);
		break;
	case 3: // start NokiMenu
		manageScreen(startNokiPhone);
		break;
	case 4:
		manageScreen(startNokiMap);
		break;
	case 5:
		manageScreen(startGuide);
		break;
	case 6:
		manageScreen(startTravelOptions); 
		break;
	default: // error
	
		std::cout << "Error Wrong return value at " << &func << "\n";
	}
	return 0;
}