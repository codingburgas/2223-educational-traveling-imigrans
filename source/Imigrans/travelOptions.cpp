#include "main.h"
#include "sideSwiper.h"
#include <unordered_map>

const int planeValue = 200, trainValue = 30, busValue = 50;


int startTravelOptions()
{
	// loading screen

	win.setActive(false);
	std::thread loading(loadingScreen);

	// prolong loading
	//using namespace std::chrono_literals;
	//std::this_thread::sleep_for(1500ms);



	sf::RectangleShape background(sf::Vector2f(WIDTH, HEIGHT));
	sf::RectangleShape nokiPhone(sf::Vector2f(WIDTH, HEIGHT));
	sf::RectangleShape pointerHand(sf::Vector2f(WIDTH / 3.f, HEIGHT));

	sf::RectangleShape planeIcon(sf::Vector2f(WIDTH / 4.f, HEIGHT / 5.f));
	sf::RectangleShape trainIcon(sf::Vector2f(WIDTH / 4.5f, HEIGHT / 5.f));
	sf::RectangleShape busIcon(sf::Vector2f(WIDTH / 4.5f, HEIGHT / 5.f));

	sf::RectangleShape planeCostButton(sf::Vector2f(WIDTH / 4.5f, HEIGHT / 9.31f));
	sf::RectangleShape trainCostButton(sf::Vector2f(WIDTH / 4.5f, HEIGHT / 9.31f));
	sf::RectangleShape busCostButton(sf::Vector2f(WIDTH / 4.5f, HEIGHT / 9.31f));

	win.setMouseCursorVisible(false); // Hide cursor
	sf::View fixed = win.getView(); // Create a fixed view


	// Load image and create sprite

	sf::Texture planeTex; 
	sf::Texture trainTex; 
	sf::Texture busTex;
	planeTex.loadFromFile("assets/vehicles/plane.png");
	trainTex.loadFromFile("assets/vehicles/train.png");
	busTex.loadFromFile("assets/vehicles/bus.png");
	planeIcon.setTexture(&planeTex);
	trainIcon.setTexture(&trainTex);
	busIcon.setTexture(&busTex); 

	planeIcon.setPosition(sf::Vector2f(WIDTH/ 4.5f,HEIGHT / 8.f));
	trainIcon.setPosition(sf::Vector2f(WIDTH / 4.5f, HEIGHT / 2.5f));
	busIcon.setPosition(sf::Vector2f(WIDTH / 4.5f, HEIGHT / 1.5f));

	sf::Texture costButtonTex;
	costButtonTex.loadFromFile("assets/buttons/clear.png");
	planeCostButton.setPosition(sf::Vector2f(WIDTH / 1.8f, HEIGHT / 6.f));
	trainCostButton.setPosition(sf::Vector2f(WIDTH / 1.8f, HEIGHT / 2.3f));
	busCostButton.setPosition(sf::Vector2f(WIDTH / 1.8f, HEIGHT / 1.4f));

	planeCostButton.setTexture(&costButtonTex);
	trainCostButton.setTexture(&costButtonTex);
	busCostButton.setTexture(&costButtonTex);
	sf::Text planeCost;
	sf::Text trainCost; 
	sf::Text busCost; 
	
	sf::Font font; 
	if (!font.loadFromFile("assets/font/retroGaming.ttf"))
	{
		std::cout << "NO FONT BROTHER";
	}
	planeCost.setFont(font); 
	trainCost.setFont(font);
	busCost.setFont(font);

	planeCost.setString(std::to_string(planeValue)+".ol");
	trainCost.setString(std::to_string(trainValue) + ".ol");
	busCost.setString(std::to_string(busValue) + ".ol");

	planeCost.setPosition(sf::Vector2f(WIDTH / 1.65f, HEIGHT / 5.6f));
	trainCost.setPosition(sf::Vector2f(WIDTH / 1.655f, HEIGHT / 2.23f));
	busCost.setPosition(sf::Vector2f(WIDTH / 1.65f, HEIGHT / 1.37f));

	planeCost.setFillColor(sf::Color::Black); 
	trainCost.setFillColor(sf::Color::Black);
	busCost.setFillColor(sf::Color::Black);

	planeCost.setCharacterSize((unsigned)69);
	trainCost.setCharacterSize((unsigned)69);
	busCost.setCharacterSize((unsigned)69);

	sf::Texture cursorTex;
	cursorTex.loadFromFile("assets/hand/cursor.png");
	pointerHand.setTexture(&cursorTex);
	pointerHand.setOrigin(sf::Vector2f(WIDTH / 10.f, HEIGHT / 15.f));

	sf::Texture nokiPhoneTex;
	nokiPhoneTex.loadFromFile("assets/nokiTech/rotated.png");
	nokiPhone.setTexture(&nokiPhoneTex);

	sf::Texture BackgroundTex;
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
				pauseGame();
			sf::Vector2f mpos = win.mapPixelToCoords(sf::Mouse::getPosition(win));

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && planeCostButton.getGlobalBounds().contains(mpos))
			{
				valueManager('-', 200);
				return 2;
				
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && trainCostButton.getGlobalBounds().contains(mpos))
			{
				valueManager('-', 30);
				return 2;
				
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && busCostButton.getGlobalBounds().contains(mpos))
			{
				valueManager('-', 50);
				return 2;
			}

		}
		pointerHand.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(win)));
		win.clear(sf::Color::Black);
		win.setView(fixed);

		win.draw(background);
		win.draw(nokiPhone);

		win.draw(planeIcon);  win.draw(planeCostButton); win.draw(planeCost);
		win.draw(trainIcon);; win.draw(trainCostButton);  win.draw(trainCost);
		win.draw(busIcon);  win.draw(busCostButton) ;win.draw(busCost);

		currency(sf::Vector2f(WIDTH/1.3f,HEIGHT/20.f)); 
		win.draw(pointerHand);
		win.display();
	}
	return 0;
}

