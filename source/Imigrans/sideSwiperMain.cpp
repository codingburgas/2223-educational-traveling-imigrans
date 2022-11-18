#include "sideSwiper.h"

void setCurrentCountry(std::string countryCode);
void switchBgPlaces(Player& p, sf::RectangleShape& bg1, sf::RectangleShape& bg2);
sf::Clock frameTime;
sf::Time dt;
sf::Texture playerTex;
std::vector<std::string> countries = { "gr", "it","en","fr","rm","bg","sp","pl"};
std::string currentCountry = countries.at(0);
Player player(&playerTex, sf::Vector2u(3/*collumn*/, 2/*row*/), 0.3f, 1.f);
extern int mapSize = 5;
std::unordered_map<std::string, Country> europe;

int startGame()
{
	// loading screen

	win.setActive(false);
	std::thread loading(loadingScreen);
	sf::Texture *bgTex = new sf::Texture();
	sf::Texture *borderTex = new sf::Texture();
	bgTex->loadFromFile("assets/background/background.png");
	borderTex->loadFromFile("assets/objects/fireHydrant.png");
	sf::RectangleShape // Backgrounds
		bg1(sf::Vector2f(2.f*WIDTH, HEIGHT)),
		bg2(sf::Vector2f(2.f * WIDTH, HEIGHT)),
		borderBegin(sf::Vector2f(WIDTH / 22.857f, HEIGHT / 6.429f)),
		borderEnd(sf::Vector2f(WIDTH / 22.857f, HEIGHT / 6.429f));

	bg1.setPosition(0, HEIGHT / 11.613f);
	bg2.setPosition(bg1.getPosition().x - bg2.getSize().x, HEIGHT / 11.613f);
	bg1.setTexture(bgTex);
	bg2.setTexture(bgTex);

	borderBegin.setPosition(bg1.getPosition().x - borderBegin.getSize().x, HEIGHT - HEIGHT / 6.429f);
	borderEnd.setPosition(WIDTH * mapSize, HEIGHT - HEIGHT / 6.429f);

	borderBegin.setTexture(borderTex);
	borderEnd.setTexture(borderTex);

	player.setPosition(sf::Vector2f(player.getRect().getPosition().x, (HEIGHT - player.getRect().getSize().y)));
	playerTex.loadFromFile("assets/character/spriteSheet.png");
	player.setTexture(&playerTex);

	europe = makeCountries();
	setCurrentCountry(currentCountry);
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
		switchBgPlaces(player, bg1, bg2);
		win.setView(player.getView());
		player.setViewCenter(sf::Vector2f(player.getRect().getPosition().x + player.getRect().getSize().x / 2,
			player.getRect().getPosition().y - player.getRect().getSize().y / 3));

		win.clear(sf::Color::Black);
		win.draw(bg1);
		win.draw(bg2);

		for (auto it : europe.at(currentCountry).getBuildings()) {
			win.draw(it.second.getOutsideRect());
		}
		win.draw(borderBegin);
		win.draw(borderEnd);
		win.draw(player.getRect());
		
		win.display();
	}
	return 0;
}


std::unordered_map<std::string, Country> makeCountries()
{
	std::unordered_map<std::string, Country> europe;
	for (std::string& cCode : countries)
		europe.insert({ cCode, Country(cCode) });
	for (std::vector<std::string>::iterator i = countries.begin(); i != countries.end(); i++)
	{
		if (*i == currentCountry)
		{
			countries.erase(i, i);
		}
	}
	return europe;
}

void setCurrentCountry(std::string countryCode)
{
	currentCountry = countryCode;
	// load new buildings insides
	// load new npcs
}

sf::RectangleShape temp;
void switchBgPlaces(Player& p, sf::RectangleShape& bg1, sf::RectangleShape& bg2)
{
	// if player is not in bg1 than the current background is bg1
	if (!p.getRect().getGlobalBounds().intersects(bg1.getGlobalBounds()))
	{
		temp = bg1;
		bg1 = bg2;
		bg2 = temp;
	}
	// when player view edge gets close to bg1's edge bg2 moves to the closest border of bg1
	if (p.getView().getCenter().x + (player.getView().getSize().x / 2)  + WIDTH / 64>= bg1.getPosition().x + bg1.getSize().x
		&& bg2.getPosition().x != bg1.getPosition().x + bg1.getSize().x)
	{
		bg2.setPosition(bg1.getPosition().x + bg1.getSize().x, HEIGHT / 11.613f);
	}
	else if (p.getView().getCenter().x - (player.getView().getSize().x / 2) - WIDTH / 64 <= bg1.getPosition().x
		&& bg2.getPosition().x != bg1.getPosition().x - bg2.getSize().x)
	{
		bg2.setPosition(bg1.getPosition().x - bg2.getSize().x, HEIGHT / 11.613f);
	}
}