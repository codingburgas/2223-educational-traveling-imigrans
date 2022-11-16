#include "main.h"


int startGuide()
{
	// loading screen

	win.setActive(false);
	std::thread loading(loadingScreen);

	// prolong loading
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(100ms);

	sf::RectangleShape background(sf::Vector2f((float)WIDTH, (float)HEIGHT));
	background.setFillColor(sf::Color::White);

	sf::RectangleShape pointerHand(sf::Vector2f((float)WIDTH / 3.f, (float)HEIGHT));


	win.setMouseCursorVisible(false); // Hide cursor
	sf::View fixed = win.getView(); // Create a fixed view

	// Load image and create sprite
	sf::Texture cursorTex;
	cursorTex.loadFromFile("assets/hand/cursor.png");
	pointerHand.setTexture(&cursorTex);
	pointerHand.setOrigin(sf::Vector2f((float)WIDTH / 10, (float)HEIGHT / 15));


	sf::Texture BackgroundTex;
	BackgroundTex.loadFromFile("assets/phone/rotated.png");
	background.setTexture(&BackgroundTex);


	sf::Font font;
	font.loadFromFile("assets/font/Teko-Regular.ttf");
	sf::Text text;
	text.setCharacterSize(64.f);
	text.setString("Hello player, welcome to our game.\n You control the character with 'W', 'A' , 'S' , 'D' or the arrows.\n You have to press the button 'E' to enter door and talk to the NPC's.\n You complete the game buy going trough all the countries.\nThe point of the game is to come up with strategy for gaining money.");
	text.setFont(font);
	text.setFillColor(sf::Color::Green);
	text.setOutlineColor(sf::Color::White);
	text.setOutlineThickness(2.f);
	text.setPosition(sf::Vector2f((float)WIDTH / 5.9f, (float)HEIGHT / 20));

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
				return 3;
			if (e.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				return 3;

		}
		pointerHand.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(win)));
		win.clear(sf::Color::White);
		win.setView(fixed);
		win.draw(background);
		//win.draw(nokiPhone);
		win.draw(text);

		win.draw(pointerHand);
		win.display();
	}
	return 0;
}