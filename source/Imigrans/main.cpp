#include "main.h"

int main()
{
	win.setVerticalSyncEnabled(true);
	win.setFramerateLimit(60);
	manageScreen(mainMenu);
}