#include "main.h"


int startGuide()
{
	// loading screen

	win.setActive(false);
	std::thread loading(loadingScreen);

	// prolong loading
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(100ms);

	sf::RectangleShape background(sf::Vector2f(WIDTH, HEIGHT));
	background.setFillColor(sf::Color::White);

	sf::RectangleShape pointerHand(sf::Vector2f(WIDTH / 3.f, HEIGHT));
	sf::RectangleShape exitButton(sf::Vector2f(WIDTH / 4.5f, HEIGHT / 9.31f));
	exitButton.setFillColor(sf::Color::Red); 
	sf::Texture exitButtonTex;
	exitButtonTex.loadFromFile("assets/buttons/exit.png");
	exitButton.setTexture(&exitButtonTex);
	exitButton.setPosition(sf::Vector2f(WIDTH / 1.75f, HEIGHT / 1.2f));


	win.setMouseCursorVisible(false); // Hide cursor
	sf::View fixed = win.getView(); // Create a fixed view

	// Load image and create sprite
	sf::Texture cursorTex;
	cursorTex.loadFromFile("assets/hand/cursor.png");
	pointerHand.setTexture(&cursorTex);
	pointerHand.setOrigin(sf::Vector2f(WIDTH / 10.f, HEIGHT / 15.f));


	sf::Texture BackgroundTex;
	BackgroundTex.loadFromFile("assets/nokiTech/guide.png");
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
			auto mpos = win.mapPixelToCoords(sf::Mouse::getPosition(win));

			if (e.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return 3;
		
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && exitButton.getGlobalBounds().contains(mpos))
			return 3;
			
		}
		pointerHand.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(win)));
		win.clear(sf::Color::White);
		win.setView(fixed);
		win.draw(background);
		win.draw(exitButton);

		win.draw(pointerHand);
		win.display();
	}
	return 0;
} 