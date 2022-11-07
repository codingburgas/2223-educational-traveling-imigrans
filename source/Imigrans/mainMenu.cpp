#include "main.h"
using namespace sf;

int mainMenu()
{
	float bWidth = (float)WIDTH / 4, bHeight = (float)HEIGHT / 4;
	RectangleShape button(Vector2f(bWidth, bHeight));

	button.setFillColor(Color::Green);
	button.setPosition(Vector2f((WIDTH - bWidth) / 2, (HEIGHT - bHeight) / 2));

	while (win.isOpen())
	{
		Event e;
		while (win.pollEvent(e))
		{
			if (e.type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::Escape))
				return 0; // close
			if (e.type == Event::MouseButtonPressed && Mouse::isButtonPressed(Mouse::Left))
				return 2; // start game
		}

		win.clear(Color::Black);
		win.draw(button);
		win.display();
	}
	return 0;
}