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
	background.setFillColor(sf::Color::Transparent);
	sf::RectangleShape holdingHand(sf::Vector2f((float)WIDTH / 3.f, (float)HEIGHT));
	sf::RectangleShape nokiPhone(sf::Vector2f((float)WIDTH, (float)HEIGHT));
	sf::RectangleShape map(sf::Vector2f(sf::Vector2f((float)WIDTH /1.5f, (float)HEIGHT / 1.105f)));
	sf::RectangleShape pointerHand(sf::Vector2f((float)WIDTH / 3.f, (float)HEIGHT));

	sf::Texture flagTex;
	flagTex.loadFromFile("assets/objects/flag.png");
	
	//Germany Button
	sf::RectangleShape grFlag(sf::Vector2f((float)WIDTH / 30, (float)HEIGHT / 12));
	sf::RectangleShape grButton(sf::Vector2f((float)WIDTH / 16, (float)HEIGHT / 8));
	grButton.setFillColor(sf::Color::Transparent); 
	grButton.setPosition(sf::Vector2f((float)WIDTH /2.23,(float)HEIGHT /2.1));
	grFlag.setPosition(sf::Vector2f((float)WIDTH / 2.18, (float)HEIGHT / 2));
	grFlag.setFillColor(sf::Color::Transparent);
	grFlag.setTexture(&flagTex);

	

	//Italy Button
	sf::RectangleShape itFlag(sf::Vector2f((float)WIDTH / 32, (float)HEIGHT / 14));
	sf::RectangleShape itButton(sf::Vector2f((float)WIDTH / 16, (float)HEIGHT / 8));
	itButton.setFillColor(sf::Color::Transparent);
	itButton.setPosition(sf::Vector2f((float)WIDTH / 2.23, (float)HEIGHT / 1.56));
	itFlag.setPosition(sf::Vector2f((float)WIDTH / 2.15, (float)HEIGHT / 1.5));
	itFlag.setFillColor(sf::Color::Transparent);
	itFlag.setTexture(&flagTex);

	sf::RectangleShape itButton2(sf::Vector2f((float)WIDTH / 16, (float)HEIGHT / 8));
	itButton2.setFillColor(sf::Color::Transparent);
	itButton2.setPosition(sf::Vector2f((float)WIDTH / 2.05, (float)HEIGHT / 1.35));

	//England Button
	sf::RectangleShape enFlag(sf::Vector2f((float)WIDTH / 30, (float)HEIGHT / 12));
	sf::RectangleShape enButton(sf::Vector2f((float)WIDTH / 16, (float)HEIGHT / 8));
	enButton.setFillColor(sf::Color::Transparent);
	enButton.setPosition(sf::Vector2f((float)WIDTH / 3.23, (float)HEIGHT / 2.6)); 
	enFlag.setPosition(sf::Vector2f((float)WIDTH / 3, (float)HEIGHT / 2.51));
	enFlag.setFillColor(sf::Color::Transparent);
	enFlag.setTexture(&flagTex);

	//France Button
	sf::RectangleShape frFlag(sf::Vector2f((float)WIDTH / 30, (float)HEIGHT / 12));
	sf::RectangleShape frButton(sf::Vector2f((float)WIDTH / 12, (float)HEIGHT / 6));
	frButton.setFillColor(sf::Color::Transparent);
	frButton.setPosition(sf::Vector2f((float)WIDTH / 3, (float)HEIGHT / 1.8)); 
	frFlag.setPosition(sf::Vector2f((float)WIDTH / 2.9, (float)HEIGHT / 1.7));
	frFlag.setFillColor(sf::Color::Transparent);
	frFlag.setTexture(&flagTex);

	//Romania Button
	sf::RectangleShape rmFlag(sf::Vector2f((float)WIDTH / 30, (float)HEIGHT / 12));
	sf::RectangleShape rmButton(sf::Vector2f((float)WIDTH / 15, (float)HEIGHT / 12));
	rmButton.setFillColor(sf::Color::Transparent);
	rmButton.setPosition(sf::Vector2f((float)WIDTH /1.6,(float)HEIGHT / 1.6));
	rmFlag.setPosition(sf::Vector2f((float)WIDTH / 1.6, (float)HEIGHT / 1.6));
	rmFlag.setFillColor(sf::Color::Transparent);
	rmFlag.setTexture(&flagTex);

	//Bulgaria Button
	sf::RectangleShape bgFlag(sf::Vector2f((float)WIDTH / 38, (float)HEIGHT / 20));
	sf::RectangleShape bgButton(sf::Vector2f((float)WIDTH / 15, (float)HEIGHT / 14));
	bgButton.setFillColor(sf::Color::Transparent);
	bgButton.setPosition(sf::Vector2f((float)WIDTH / 1.58, (float)HEIGHT / 1.4));
	bgFlag.setPosition(sf::Vector2f((float)WIDTH / 1.53, (float)HEIGHT / 1.378));
	bgFlag.setFillColor(sf::Color::Transparent);
	bgFlag.setTexture(&flagTex);

	//Spain Button
	sf::RectangleShape spFlag(sf::Vector2f((float)WIDTH / 30, (float)HEIGHT / 12));
	sf::RectangleShape spButton(sf::Vector2f((float)WIDTH / 12, (float)HEIGHT / 7));
	spButton.setFillColor(sf::Color::Transparent);
	spButton.setPosition(sf::Vector2f((float)WIDTH / 4.5, (float)HEIGHT / 1.45));
	spFlag.setPosition(sf::Vector2f((float)WIDTH / 4, (float)HEIGHT / 1.40));
	spFlag.setFillColor(sf::Color::Transparent);
	spFlag.setTexture(&flagTex);

	//Poland Button
	sf::RectangleShape plFlag(sf::Vector2f((float)WIDTH / 30, (float)HEIGHT / 12));
	sf::RectangleShape plButton(sf::Vector2f((float)WIDTH / 16, (float)HEIGHT / 10));
	plButton.setFillColor(sf::Color::Transparent);
	plButton.setPosition(sf::Vector2f((float)WIDTH / 1.8, (float)HEIGHT / 2.15));
	plFlag.setPosition(sf::Vector2f((float)WIDTH / 1.8, (float)HEIGHT / 2.15));
	plFlag.setFillColor(sf::Color::Transparent);
	plFlag.setTexture(&flagTex);

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
			auto mpos = win.mapPixelToCoords(sf::Mouse::getPosition(win));

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && grButton.getGlobalBounds().contains(mpos))
			{
				setCurrentCountry("gr");
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && itButton.getGlobalBounds().contains(mpos) or sf::Mouse::isButtonPressed(sf::Mouse::Left) && itButton2.getGlobalBounds().contains(mpos))
			{
				setCurrentCountry("it");
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && enButton.getGlobalBounds().contains(mpos))
			{
				setCurrentCountry("en");
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && frButton.getGlobalBounds().contains(mpos))
			{
				setCurrentCountry("fr");
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && rmButton.getGlobalBounds().contains(mpos))
			{
				setCurrentCountry("rm");
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && bgButton.getGlobalBounds().contains(mpos))
			{
				setCurrentCountry("bg");

			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && spButton.getGlobalBounds().contains(mpos))
			{
				setCurrentCountry("sp");

			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plButton.getGlobalBounds().contains(mpos))
			{
				setCurrentCountry("pl");

			}

		}
		pointerHand.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(win))); 
		win.clear(sf::Color::Black);
		win.setView(fixed);

		win.draw(background);
		win.draw(holdingHand);
		win.draw(nokiPhone);
		win.draw(map);
		win.draw(grButton);		win.draw(grFlag);
		win.draw(itButton);		win.draw(itFlag);
		win.draw(itButton2);	
		win.draw(enButton);		win.draw(enFlag);
		win.draw(frButton);		win.draw(frFlag);
		win.draw(rmButton);		win.draw(rmFlag);
		win.draw(bgButton);		win.draw(bgFlag);
		win.draw(spButton);		win.draw(spFlag);
		win.draw(plButton);		win.draw(plFlag);


		
		win.draw(pointerHand);
		win.display();
	}
	return 0;
}

