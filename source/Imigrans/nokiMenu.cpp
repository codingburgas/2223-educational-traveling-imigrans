#include "main.h"

int startNokiPhone()
{
	// loading screen

	win.setActive(false);
	std::thread loading(loadingScreen);

	//prolong loading
	//using namespace std::chrono_literals;
	//std::this_thread::sleep_for(1000ms);

	sf::RectangleShape background(sf::Vector2f(WIDTH, HEIGHT));
	background.setFillColor(sf::Color::White);
	sf::RectangleShape holdingHand(sf::Vector2f(WIDTH / 3.f, HEIGHT));
	sf::RectangleShape nokiPhone(sf::Vector2f(WIDTH / 4.f, HEIGHT / 1.2f));
	sf::RectangleShape playButton(sf::Vector2f(WIDTH / 4.5f, HEIGHT / 9.31f));
	sf::RectangleShape guideButton(sf::Vector2f(WIDTH / 4.5f, HEIGHT / 9.31f));
	sf::RectangleShape exitButton(sf::Vector2f(WIDTH / 4.5f, HEIGHT / 9.31f));
	sf::RectangleShape pointerHand(sf::Vector2f(WIDTH / 3.f, HEIGHT));

	sf::View fixed = win.getView(); // Create a fixed view
	fixed.setCenter(WIDTH / 2, HEIGHT / 2);

	// Load image and create sprite
	sf::Texture cursorTex;
	cursorTex.loadFromFile("assets/hand/cursor.png");
	pointerHand.setTexture(&cursorTex);
	pointerHand.setOrigin(sf::Vector2f(WIDTH / 10.f, HEIGHT / 10.f));

	sf::Texture holderTex;
	holderTex.loadFromFile("assets/hand/phoneHolder.png");
	holdingHand.setTexture(&holderTex);
	holdingHand.setPosition(WIDTH / 2.f - WIDTH / 4.f, HEIGHT / 5.f);

	sf::Texture nokiPhoneTex;
	nokiPhoneTex.loadFromFile("assets/nokiTech/empty.png");
	nokiPhone.setTexture(&nokiPhoneTex);
	nokiPhone.setPosition(WIDTH / 2.6f, HEIGHT / 4.f - HEIGHT / 6.f);

	sf::Texture BackgroundTex;
	BackgroundTex.loadFromFile("assets/background/phoneBackground.png");

	background.setTexture(&BackgroundTex);

	sf::Texture playButtonTex;
	playButtonTex.loadFromFile("assets/buttons/play.png");
	playButton.setTexture(&playButtonTex);
	playButton.setPosition(sf::Vector2f(WIDTH / 2.51f, HEIGHT / 4.0f));

	sf::Texture guideButtonTex;
	guideButtonTex.loadFromFile("assets/buttons/guide.png");
	guideButton.setTexture(&guideButtonTex);
	guideButton.setPosition(sf::Vector2f(WIDTH / 2.51f, HEIGHT / 2.5f));

	sf::Texture exitButtonTex;
	exitButtonTex.loadFromFile("assets/buttons/exit.png");
	exitButton.setTexture(&exitButtonTex);
	exitButton.setPosition(sf::Vector2f(WIDTH / 2.51f, HEIGHT / 1.75f));
	// exit loading

	loaded = true;
	loading.join(); // wait for the thread function to finish
	win.setActive(true); // set window as an OpenGL render target

	while (win.isOpen())
	{
		auto mpos = win.mapPixelToCoords(sf::Mouse::getPosition(win));
		sf::Event e;
		while (win.pollEvent(e))
		{

			if (e.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return 0;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && playButton.getGlobalBounds().contains(mpos))
				return 4; // start NokiMap

			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && guideButton.getGlobalBounds().contains(mpos))
				return 5; // start guide

			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && exitButton.getGlobalBounds().contains(mpos))
				return 0; // close
		}

		pointerHand.setPosition(mpos); // Set position
		win.clear(sf::Color::Black);
		win.setView(fixed);
		win.draw(background);
		win.draw(holdingHand);
		win.draw(nokiPhone);
		win.draw(playButton);
		win.draw(guideButton);
		win.draw(exitButton);

		
		win.draw(pointerHand);
		win.display();
	}
	return 0;
}

