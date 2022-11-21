#include "sideSwiper.h"



bool startQuest(int quest)
{
	win.setMouseCursorVisible(true);
	sf::View fixed = win.getView(); // Create a fixed view
	fixed.setCenter(WIDTH / 2, HEIGHT / 2);

	// loading screen

	win.setActive(false);
	std::thread loading(loadingScreen);


	float ratio = 0.786;
	sf::RectangleShape background(sf::Vector2f(WIDTH, HEIGHT));
	sf::RectangleShape result(sf::Vector2f(WIDTH, HEIGHT));
	result.setFillColor(sf::Color::Transparent);
	sf::Texture bgTex, bgTexCorrect, bgTexWrong;
	bgTex.loadFromFile("assets/nokiTech/laptop.png");
	bgTexCorrect.loadFromFile("assets/nokiTech/laptopCorrect.png");
	bgTexWrong.loadFromFile("assets/nokiTech/laptopWrong.png");
	background.setTexture(&bgTex);

	sf::RectangleShape checkButton(sf::Vector2f(WIDTH / 9.014f, HEIGHT / 18.621f));
	sf::Texture cbTex;
	cbTex.loadFromFile("assets/buttons/check.png");
	checkButton.setTexture(&cbTex);
	checkButton.setPosition(sf::Vector2f(WIDTH * 0.667f, HEIGHT * 0.7f));
	checkButton.setFillColor(sf::Color::Red);

	sf::RectangleShape question(sf::Vector2f(WIDTH / 3.491f, HEIGHT / 1.834f));
	sf::Texture qTex;
	qTex.loadFromFile("assets/quest/" + std::to_string(quest) + "/question.png");
	question.setTexture(&qTex);
	//question.setFillColor(sf::Color::Green);
	question.setPosition(sf::Vector2f(363.f, 203.f));
	std::vector < sf::FloatRect> dropZones(3);

	bool correct[3] = {0,0,0};

	// YOU SHALL IGNORE ALL THAT IS GOING ON IN THIS SWITCH
	// please
	// go to line 200

	switch (quest)
	{
	case 1:
		dropZones[0].left = question.getPosition().x;
		dropZones[0].top = question.getPosition().y + 434 * ratio;
		dropZones[0].width = question.getSize().x;
		dropZones[0].height = HEIGHT/ 54.f * ratio;

		dropZones[1].left = question.getPosition().x;
		dropZones[1].top = question.getPosition().y + 486 * ratio;
		dropZones[1].width = question.getSize().x;
		dropZones[1].height = HEIGHT / 54.f * ratio;

		dropZones[2].left = question.getPosition().x;
		dropZones[2].top = question.getPosition().y + 522 * ratio;
		dropZones[2].width = question.getSize().x;
		dropZones[2].height = HEIGHT / 54.f * ratio;
		break;
	case 2:
		dropZones[0].left = question.getPosition().x;
		dropZones[0].top = question.getPosition().y + 352 * ratio;
		dropZones[0].width = question.getSize().x;
		dropZones[0].height = HEIGHT / 54.f * ratio;

		dropZones[1].left = question.getPosition().x;
		dropZones[1].top = question.getPosition().y + 532 * ratio;
		dropZones[1].width = question.getSize().x;
		dropZones[1].height = HEIGHT / 54.f * ratio;

		dropZones[2].left = question.getPosition().x;
		dropZones[2].top = question.getPosition().y + 567 * ratio;
		dropZones[2].width = question.getSize().x;
		dropZones[2].height = HEIGHT / 54.f * ratio;
		break;
	case 3:
		dropZones[0].left = question.getPosition().x;
		dropZones[0].top = question.getPosition().y + 302 * ratio;
		dropZones[0].width = question.getSize().x;
		dropZones[0].height = HEIGHT / 54.f * ratio;

		dropZones[1].left = question.getPosition().x;
		dropZones[1].top = question.getPosition().y + 482 * ratio;
		dropZones[1].width = question.getSize().x;
		dropZones[1].height = HEIGHT / 54.f * ratio;

		dropZones[2].left = question.getPosition().x;
		dropZones[2].top = question.getPosition().y + 571 * ratio;
		dropZones[2].width = question.getSize().x;
		dropZones[2].height = HEIGHT / 54.f * ratio;
		break;
	case 4:
		dropZones[0].left = question.getPosition().x;
		dropZones[0].top = question.getPosition().y + 283 * ratio;
		dropZones[0].width = question.getSize().x;
		dropZones[0].height = HEIGHT / 54.f * ratio;

		dropZones[1].left = question.getPosition().x;
		dropZones[1].top = question.getPosition().y + 499 * ratio;
		dropZones[1].width = question.getSize().x;
		dropZones[1].height = HEIGHT / 54.f * ratio;

		dropZones[2].left = question.getPosition().x;
		dropZones[2].top = question.getPosition().y + 552 * ratio;
		dropZones[2].width = question.getSize().x;
		dropZones[2].height = HEIGHT / 54.f * ratio;
		break;
	case 5:
		dropZones[0].left = question.getPosition().x;
		dropZones[0].top = question.getPosition().y + 412 * ratio;
		dropZones[0].width = question.getSize().x;
		dropZones[0].height = HEIGHT / 54.f * ratio;

		dropZones[1].left = question.getPosition().x;
		dropZones[1].top = question.getPosition().y + 564 * ratio;
		dropZones[1].width = question.getSize().x;
		dropZones[1].height = HEIGHT / 54.f * ratio;

		dropZones[2].left = question.getPosition().x;
		dropZones[2].top = question.getPosition().y + 604 * ratio;
		dropZones[2].width = question.getSize().x;
		dropZones[2].height = HEIGHT / 54.f * ratio;
		break;
	case 6:
		dropZones[0].left = question.getPosition().x;
		dropZones[0].top = question.getPosition().y + 345 * ratio;
		dropZones[0].width = question.getSize().x;
		dropZones[0].height = HEIGHT / 54.f * ratio;

		dropZones[1].left = question.getPosition().x;
		dropZones[1].top = question.getPosition().y + 382 * ratio;
		dropZones[1].width = question.getSize().x;
		dropZones[1].height = HEIGHT / 54.f * ratio;

		dropZones[2].left = question.getPosition().x;
		dropZones[2].top = question.getPosition().y + 508 * ratio;
		dropZones[2].width = question.getSize().x;
		dropZones[2].height = HEIGHT / 54.f * ratio;
		break;
	case 7:
		dropZones[0].left = question.getPosition().x;
		dropZones[0].top = question.getPosition().y + 540 * ratio;
		dropZones[0].width = question.getSize().x;
		dropZones[0].height = HEIGHT / 54.f * ratio;

		dropZones[1].left = question.getPosition().x;
		dropZones[1].top = question.getPosition().y + 588 * ratio;
		dropZones[1].width = question.getSize().x;
		dropZones[1].height = HEIGHT / 54.f * ratio;

		dropZones[2].left = question.getPosition().x;
		dropZones[2].top = question.getPosition().y + 620 * ratio;
		dropZones[2].width = question.getSize().x;
		dropZones[2].height = HEIGHT / 54.f * ratio;
		break;
	case 8:
		dropZones[0].left = question.getPosition().x;
		dropZones[0].top = question.getPosition().y + 365 * ratio;
		dropZones[0].width = question.getSize().x;
		dropZones[0].height = HEIGHT / 54.f * ratio;

		dropZones[1].left = question.getPosition().x;
		dropZones[1].top = question.getPosition().y + 417 * ratio;
		dropZones[1].width = question.getSize().x;
		dropZones[1].height = HEIGHT / 54.f * ratio;

		dropZones[2].left = question.getPosition().x;
		dropZones[2].top = question.getPosition().y + 517 * ratio;
		dropZones[2].width = question.getSize().x;
		dropZones[2].height = HEIGHT / 54.f * ratio;
		break;
	case 9:
		dropZones[0].left = question.getPosition().x;
		dropZones[0].top = question.getPosition().y + 300 * ratio;
		dropZones[0].width = question.getSize().x;
		dropZones[0].height = HEIGHT / 54.f * ratio;

		dropZones[1].left = question.getPosition().x;
		dropZones[1].top = question.getPosition().y + 419 * ratio;
		dropZones[1].width = question.getSize().x;
		dropZones[1].height = HEIGHT / 54.f * ratio;

		dropZones[2].left = question.getPosition().x;
		dropZones[2].top = question.getPosition().y + 536 * ratio;
		dropZones[2].width = question.getSize().x;
		dropZones[2].height = HEIGHT / 54.f * ratio;
		break;
	case 10:
		dropZones[0].left = question.getPosition().x;
		dropZones[0].top = question.getPosition().y + 223 * ratio;
		dropZones[0].width = question.getSize().x;
		dropZones[0].height = HEIGHT / 54.f * ratio;

		dropZones[1].left = question.getPosition().x;
		dropZones[1].top = question.getPosition().y + 314 * ratio;
		dropZones[1].width = question.getSize().x;
		dropZones[1].height = HEIGHT / 54.f * ratio;

		dropZones[2].left = question.getPosition().x;
		dropZones[2].top = question.getPosition().y + 388 * ratio;
		dropZones[2].width = question.getSize().x;
		dropZones[2].height = HEIGHT / 54.f * ratio;
		break;
	default:
		break;
	}

	std::vector < sf::RectangleShape> answers(3);
	std::vector<sf::Texture> aTex(3);

	for (size_t i = 0; i < aTex.size(); ++i) {
		aTex.at(i).loadFromFile("assets/quest/" + std::to_string(quest) + "/cut" + std::to_string(i + 1) + ".png");
	}

	for (size_t i = 0; i < answers.size(); ++i) {
		answers[i].setSize(sf::Vector2f(WIDTH / 3.491f, HEIGHT / 68.729f));
		answers[i].setPosition(sf::Vector2f(1007.f, 73 + 192.715 * (i + 1)));
		answers[i].setTexture(&aTex[i]);
	}

	sf::RectangleShape* curAns = nullptr;

	// exit loading

	loaded = true;
	loading.join(); // wait for the thread function to finish
	win.setActive(true); // set window as an OpenGL render target
	sf::Vector2f lastPos(0,0);
	while (true)
	{
		sf::Vector2f mpos = win.mapPixelToCoords(sf::Mouse::getPosition(win));
		sf::Event e;
		while (win.pollEvent(e))
		{
			if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
				return false;
			if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left && curAns == nullptr)
			{
				for (auto& a : answers)
				{
					if (a.getGlobalBounds().contains(mpos))
					{
						lastPos = a.getPosition();
						curAns = &a;
						break;
					}
				}
			}
			if (e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && curAns != nullptr)
			{
				for (auto& dz : dropZones)
				{
					if (dz.contains(mpos))
					{
						curAns->setPosition(dz.left, dz.top);
						lastPos = curAns->getPosition();
					}
					curAns->setPosition(lastPos);
				}
				curAns = nullptr;
			}
			if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left && curAns == nullptr && checkButton.getGlobalBounds().contains(mpos))
			{
				bool correct = true;
				for (int i = 0; i < 3; ++i)
				{
					if (!dropZones[i].intersects(answers[i].getGlobalBounds()))
					{
						correct = false;
						break;
					}
				}
				result.setFillColor(sf::Color::White);
				if (correct)
				{
					result.setTexture(&bgTexCorrect);
					valueManager('+', 50);
				}
				else
				{
					result.setTexture(&bgTexWrong);
					valueManager('-', 50);
				}
			}
		}
		if (curAns != nullptr)
			curAns->setPosition(mpos.x - curAns->getSize().x/2, mpos.y - curAns->getSize().y/2);

		win.setView(fixed);
		win.clear(sf::Color(16, 0, 31, 255));
		win.draw(background);
		win.draw(question);
		
		for (auto& a : answers)
			win.draw(a);
		win.draw(checkButton);
		
		win.draw(result);
		win.display();
		if (result.getFillColor() != sf::Color::Transparent)
		{
			using namespace std::chrono_literals;
			std::this_thread::sleep_for(1000ms);
			return result.getTexture() == &bgTexCorrect;
		}
	}
}