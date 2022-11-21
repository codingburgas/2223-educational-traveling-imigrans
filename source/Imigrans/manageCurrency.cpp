#include "main.h"


void valueManager(char sym, int sum);
int currencyCount = 1000;


void currency(sf::Vector2f pos)
{
	
		sf::RectangleShape currency(sf::Vector2f(WIDTH / 16, HEIGHT / 8));

		sf::Texture currencyTex;
		currencyTex.loadFromFile("assets/currency/currency.png");
		currency.setTexture(&currencyTex);
		currency.setPosition(pos);


		sf::Vector2f textPos(pos.x - WIDTH / 50, pos.y);

		sf::Font font;
		font.loadFromFile("assets/font/Teko-Bold.ttf");

		if (!font.loadFromFile("assets/font/Teko-Bold.ttf"))
			std::cout << "No font brother?";

		sf::Text text;
		std::string displayCurrencyCount;
		displayCurrencyCount = std::to_string(currencyCount) + ".ol";
		text.setCharacterSize(80);
		text.setString(displayCurrencyCount);
		text.setPosition(textPos);
		text.setFont(font);
		text.setFillColor(sf::Color::White);
		text.setOutlineColor(sf::Color::Black);
		text.setOutlineThickness(2.f);




		win.draw(currency);
		win.draw(text);
	
}

void valueManager(char sym, int value)
{
	if (sym == '+')
		currencyCount += value;
	if (sym == '-')
		currencyCount -= value;
}
