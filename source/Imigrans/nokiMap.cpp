#include "main.h"
#include "sideSwiper.h"
#include <unordered_map>

int startNokiMap()
{
	// loading screen

	win.setActive(false);
	std::thread loading(loadingScreen);

	// prolong loading
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(1500ms);

	

	sf::RectangleShape background(sf::Vector2f(WIDTH, HEIGHT));
	sf::RectangleShape nokiPhone(sf::Vector2f(WIDTH, HEIGHT));
	sf::RectangleShape map(sf::Vector2f(sf::Vector2f(WIDTH /1.5f, HEIGHT / 1.105f)));
	sf::RectangleShape pointerHand(sf::Vector2f(WIDTH / 3.f, HEIGHT));

	sf::Texture flagTex;
	flagTex.loadFromFile("assets/objects/flag.png");
	std::unordered_map<std::string, sf::RectangleShape> cButtons;
	std::unordered_map<std::string, sf::RectangleShape> cFlags;

	//Germany Button
	cButtons["gr"] = sf::RectangleShape(sf::Vector2f(WIDTH / 16.f, HEIGHT / 8.f));
	
	cButtons.at("gr").setFillColor(sf::Color::Transparent);
	cButtons.at("gr").setPosition(sf::Vector2f(WIDTH /2.23f,HEIGHT /2.1f));

	cFlags["gr"] = sf::RectangleShape(sf::Vector2f(WIDTH / 30.f, HEIGHT / 12.f));

	cFlags.at("gr").setPosition(sf::Vector2f(WIDTH / 2.15f, HEIGHT / 2.1f));


	//Italy Button
	
	cButtons["it"] = sf::RectangleShape(sf::Vector2f(WIDTH / 16.f, HEIGHT / 8.f));
	cButtons.at("it").setFillColor(sf::Color::Transparent);
	cButtons.at("it").setPosition(sf::Vector2f(WIDTH / 2.23f, HEIGHT / 1.56f));

	cFlags["it"] = sf::RectangleShape(sf::Vector2f(WIDTH / 32.f, HEIGHT / 14.f));
	cFlags.at("it").setPosition(sf::Vector2f(WIDTH / 2.10f, HEIGHT / 1.5f));

	cButtons["it2"] = sf::RectangleShape(sf::Vector2f(WIDTH / 16.f, HEIGHT / 8.f));
	cButtons.at("it2").setFillColor(sf::Color::Transparent);
	cButtons.at("it2").setPosition(sf::Vector2f(WIDTH / 2.05f, HEIGHT / 1.35f));

	//England Button
	
	cButtons["en"] = sf::RectangleShape(sf::Vector2f(WIDTH / 16.f, HEIGHT / 8.f));
	cButtons.at("en").setFillColor(sf::Color::Transparent);
	cButtons.at("en").setPosition(sf::Vector2f(WIDTH / 3.23f, HEIGHT / 2.6f));

	cFlags["en"] = sf::RectangleShape(sf::Vector2f(WIDTH / 30.f, HEIGHT / 12.f));
	cFlags.at("en").setPosition(sf::Vector2f(WIDTH / 2.9f, HEIGHT / 2.8f));

	//France Button
	
	cButtons["fr"] = sf::RectangleShape(sf::Vector2f(WIDTH / 12.f, HEIGHT / 6.f));
	cButtons.at("fr").setFillColor(sf::Color::Transparent);
	cButtons.at("fr").setPosition(sf::Vector2f(WIDTH / 3.f, HEIGHT / 1.8f)); 

	cFlags["fr"] = sf::RectangleShape(sf::Vector2f(WIDTH / 30.f, HEIGHT / 12.f));
	cFlags.at("fr").setPosition(sf::Vector2f(WIDTH / 2.82f, HEIGHT / 1.7f));

	//Romania Button
	
	cButtons["rm"] = sf::RectangleShape(sf::Vector2f(WIDTH / 15.f, HEIGHT / 12.f));
	cButtons.at("rm").setFillColor(sf::Color::Transparent);
	cButtons.at("rm").setPosition(sf::Vector2f(WIDTH /1.6f,HEIGHT / 1.6f));

	cFlags["rm"] = sf::RectangleShape(sf::Vector2f(WIDTH / 30.f, HEIGHT / 12.f));
	cFlags.at("rm").setPosition(sf::Vector2f(WIDTH / 1.55f, HEIGHT / 1.6f));

	//Bulgaria Button
	
	cButtons["bg"] = sf::RectangleShape(sf::Vector2f(WIDTH / 15.f, HEIGHT / 14.f));
	cButtons.at("bg").setFillColor(sf::Color::Transparent);
	cButtons.at("bg").setPosition(sf::Vector2f(WIDTH / 1.58f, HEIGHT / 1.4f));

	cFlags["bg"] = sf::RectangleShape(sf::Vector2f(WIDTH / 38.f, HEIGHT / 20.f));
	cFlags.at("bg").setPosition(sf::Vector2f(WIDTH / 1.53f, HEIGHT / 1.378f));

	//Spain Button
	
	cButtons["sp"] = sf::RectangleShape(sf::Vector2f(WIDTH / 12.f, HEIGHT / 7.f));
	cButtons.at("sp").setFillColor(sf::Color::Transparent);
	cButtons.at("sp").setPosition(sf::Vector2f(WIDTH / 4.5f, HEIGHT / 1.45f));
	
	cFlags["sp"] = sf::RectangleShape(sf::Vector2f(WIDTH / 30.f, HEIGHT / 12.f));
	cFlags.at("sp").setPosition(sf::Vector2f(WIDTH / 4.f, HEIGHT / 1.40f));

	//Poland Button
	
	cButtons["pl"] = sf::RectangleShape(sf::Vector2f(WIDTH / 16.f, HEIGHT / 10.f));
	cButtons.at("pl").setFillColor(sf::Color::Transparent);
	cButtons.at("pl").setPosition(sf::Vector2f(WIDTH / 1.8f, HEIGHT / 2.15f));
	
	cFlags["pl"] = sf::RectangleShape(sf::Vector2f(WIDTH / 30.f, HEIGHT / 12.f));
	cFlags.at("pl").setPosition(sf::Vector2f(WIDTH / 1.77f, HEIGHT / 2.15f));


	for (auto& flag : cFlags)
		flag.second.setTexture(&flagTex);

	win.setMouseCursorVisible(false); // Hide cursor
	sf::View fixed = win.getView(); // Create a fixed view


	// Load image and create sprite
	sf::Texture cursorTex;
	cursorTex.loadFromFile("assets/hand/cursor.png");
	pointerHand.setTexture(&cursorTex);
	pointerHand.setOrigin(sf::Vector2f(WIDTH / 10.f, HEIGHT / 15.f));

	sf::Texture nokiPhoneTex;
	nokiPhoneTex.loadFromFile("assets/nokiTech/rotated.png");
	nokiPhone.setTexture(&nokiPhoneTex);
	
	
	sf::Texture mapTex;
	mapTex.loadFromFile("assets/map/map.png");
	map.setTexture(&mapTex);
	sf::Texture BackgroundTex;
	map.setPosition(sf::Vector2f(WIDTH / 6.f, HEIGHT/21.f));


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
			sf::Vector2f mpos = win.mapPixelToCoords(sf::Mouse::getPosition(win));

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cButtons.at("gr").getGlobalBounds().contains(mpos))
			{
				currentCountry = "gr";
				return 6; 
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (cButtons.at("it").getGlobalBounds().contains(mpos) || cButtons.at("it2").getGlobalBounds().contains(mpos)))
			{
				currentCountry = "it";
				return 6;
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cButtons.at("en").getGlobalBounds().contains(mpos))
			{
				currentCountry = "en";
				return 6;
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cButtons.at("fr").getGlobalBounds().contains(mpos))
			{
				currentCountry = "fr";
				return 6;
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cButtons.at("rm").getGlobalBounds().contains(mpos))
			{
				currentCountry = "rm";
				return 6;
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cButtons.at("bg").getGlobalBounds().contains(mpos))
			{
				currentCountry = "bg";
				return 6;
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cButtons.at("sp").getGlobalBounds().contains(mpos))
			{
				currentCountry = "sp";
				return 6;

			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cButtons.at("pl").getGlobalBounds().contains(mpos))
			{
				currentCountry = "pl";
				return 6;
			}

		}
		pointerHand.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(win))); 
		win.clear(sf::Color::Black);
		win.setView(fixed);

		win.draw(background);
		win.draw(nokiPhone);
		win.draw(map);

		for (auto flag : cFlags)
			win.draw(flag.second);

		win.draw(pointerHand);
		win.display();
	}
	return 0;
}

