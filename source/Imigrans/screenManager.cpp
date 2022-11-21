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
	case 4: // start NokiMap
		manageScreen(startNokiMap);
		break;
	case 5:	// start guide
		manageScreen(startGuide);
		break;
	case 6: // start TravelOptions
		manageScreen(startTravelOptions); 
		break;
	case 7:
		manageScreen(restart);
		break;
	default: // error
		std::cout << "Error Wrong return value at " << &func << "\n";
	}
	return 0;
}