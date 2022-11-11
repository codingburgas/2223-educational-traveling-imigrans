#include "sideSwiper.h"


sf::Clock frameTime;
sf::Time dt;
sf::Texture playerTex;


Player player(&playerTex, sf::Vector2u(3/*collumn*/, 2/*row*/), 0.3f, 1.5f);
extern int mapSize = 4;

int startGame()
{
	// loading screen

	win.setActive(false);
	std::thread loading(loadingScreen);
	std::string currentCountry = "gr";

	sf::RectangleShape background(sf::Vector2f((float)WIDTH * mapSize, (float)HEIGHT));
	background.setFillColor(sf::Color::White);

	player.setPosition(sf::Vector2f(player.getRect().getPosition().x, ((float)HEIGHT - player.getRect().getSize().y)));
	playerTex.loadFromFile("assets/character/spriteSheet.png");
	player.setTexture(&playerTex);

	auto europe = makeCountries();

	// exit loading

	loaded = true;
	loading.join(); // wait for the thread function to finish
	win.setActive(true); // set window as an OpenGL render target

	while (win.isOpen())
	{
		dt = frameTime.restart();

		sf::Event e;
		while (win.pollEvent(e))
		{
			if (e.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return 0; // close
		}

		player.update();


		win.setView(player.getView());
		player.setViewCenter(sf::Vector2f(player.getRect().getPosition().x + player.getRect().getSize().x / 2,
			player.getRect().getPosition().y - player.getRect().getSize().y / 3));

		win.clear(sf::Color::Black);
		win.draw(background);

		for (auto it : europe.at("gr").getBuildings()) {
			win.draw(it.second.getOutsideRect());
			//std::cout << "x: "
			//	<<it.second.getOutsideRect().getPosition().x << " y: " << it.second.getOutsideRect().getPosition().y << std::endl;
		}

		win.draw(player.getRect());
		win.display();
	}
	return 0;
}


std::unordered_map<std::string, Country> makeCountries()
{
	std::unordered_map<std::string, Country> europe;
	europe.insert({ "gr", Country("gr") });
	europe.insert({ "it", Country("it") });
	europe.insert({ "en", Country("en") });
	europe.insert({ "fr", Country("fr") });
	europe.insert({ "rm", Country("rm") });
	europe.insert({ "bg", Country("bg") });
	europe.insert({ "sp", Country("sp") });
	europe.insert({ "pl", Country("pl") });
	return europe;
}