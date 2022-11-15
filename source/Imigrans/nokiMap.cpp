#include "main.h"

int startNokiMap()
{
	// loading screen

	win.setActive(false);
	std::thread loading(loadingScreen);

	// prolong loading
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(1500ms);

	sf::RectangleShape background(sf::Vector2f((float)WIDTH, (float)HEIGHT));
	background.setFillColor(sf::Color::White);
	sf::RectangleShape holdingHand(sf::Vector2f((float)WIDTH / 3.f, (float)HEIGHT));
	sf::RectangleShape nokiPhone(sf::Vector2f((float)WIDTH, (float)HEIGHT));
	sf::RectangleShape map(sf::Vector2f(sf::Vector2f((float)WIDTH /1.5f, (float)HEIGHT / 1.105f)));
	sf::RectangleShape pointerHand(sf::Vector2f((float)WIDTH / 3.f, (float)HEIGHT));


	win.setMouseCursorVisible(false); // Hide cursor
	sf::View fixed = win.getView(); // Create a fixed view

	// Load image and create sprite
	sf::Texture cursorTex;
	cursorTex.loadFromFile("assets/hand/cursor.png");
	pointerHand.setTexture(&cursorTex);
	pointerHand.setOrigin(sf::Vector2f((float)WIDTH / 10, (float)HEIGHT / 15));

	sf::Texture holderTex;
	holderTex.loadFromFile("assets/hand/phoneHolder.png");
	holdingHand.setTexture(&holderTex);
	holdingHand.setPosition(sf::Vector2f((float)WIDTH / 2.f - (float)WIDTH / 4.f, (float)HEIGHT / 5.f));

	sf::Texture nokiPhoneTex;
	nokiPhoneTex.loadFromFile("assets/phone/rotated.png");
	nokiPhone.setTexture(&nokiPhoneTex);
	
	
	sf::Texture mapTex;
	mapTex.loadFromFile("assets/map/map.png");
	map.setTexture(&mapTex);
	sf::Texture BackgroundTex;
	map.setPosition(sf::Vector2f((float)WIDTH / 6.f, (float)HEIGHT/21.f));


	BackgroundTex.loadFromFile("assets/background/phoneBackground.png");

	background.setTexture(&BackgroundTex);

	


	// exit loading

	loaded = true;
	loading.join(); // wait for the thread function to finish
	win.setActive(true); // set window as an OpenGL render target

	while (win.isOpen())
	{
		sf::Event e;
		while (win.pollEvent(e))
		{

			if (e.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return 0; // close
			if (e.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				return 2; 

		}
		pointerHand.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(win))); 
		win.clear(sf::Color::Black);
		win.setView(fixed);
		win.draw(background);
		win.draw(holdingHand);
		win.draw(nokiPhone);
		win.draw(map);

		
		win.draw(pointerHand);
		win.display();
	}
	return 0;
}

