#include "main.h"

int startNokiPhone()
{

	sf::RectangleShape background(sf::Vector2f((float)WIDTH, (float)HEIGHT));
	background.setFillColor(sf::Color::White);
	sf::RectangleShape holdingHand(sf::Vector2f(WIDTH / 3, HEIGHT   ));
	sf::RectangleShape nokiPhone(sf::Vector2f(WIDTH / 4, HEIGHT / 1.2));
	sf::RectangleShape map;
	sf::RectangleShape pointerHand(sf::Vector2f(WIDTH / 3, HEIGHT));


	win.setMouseCursorVisible(false); // Hide cursor
	sf::View fixed = win.getView(); // Create a fixed view

	// Load image and create sprite
	sf::Texture cursorTex;
	cursorTex.loadFromFile("assets/hand/cursor.png");
	pointerHand.setTexture(&cursorTex); 

		sf::Texture holderTex;
	holderTex.loadFromFile("assets/hand/phoneHolder.png");
	holdingHand.setTexture(&holderTex);
	holdingHand.setPosition(WIDTH/2-WIDTH/4,HEIGHT/5);
	
	sf::Texture nokiPhoneTex; 
	nokiPhoneTex.loadFromFile("assets/phone/empty.png");
	nokiPhone.setTexture(&nokiPhoneTex);
	nokiPhone.setPosition(WIDTH / 2.6, HEIGHT / 4-HEIGHT/6 );

	sf::Texture BackgroundTex; 
	BackgroundTex.loadFromFile("assets/background/phoneBg.png");
	background.setTexture(&BackgroundTex);

	while (win.isOpen())
	{
		sf::Event e;
		while (win.pollEvent(e))
		{

			if (e.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return 0; // close
			if (e.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				manageScreen(startGame);

		}
		pointerHand.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(win))); // Set position
		win.clear(sf::Color::Black);
		win.setView(fixed);
		win.draw(background);
		win.draw(holdingHand);
		win.draw(nokiPhone);
	
		win.draw(pointerHand);
		win.display();
	}
	return 0;
}

