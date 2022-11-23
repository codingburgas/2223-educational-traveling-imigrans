#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <thread>
#include <chrono>

int		manageScreen(std::function<int()> func);

int		restart();

int		startGame();
int		startNokiPhone();
int		startNokiMap();
int		startGuide();
int		startTravelOptions();
int		gameOver();

bool	startQuest(int quest);

void	loadingScreen();
void	currency(sf::Vector2f pos);
void	valueManager(char sym, int sum);
void	pauseGame();


extern bool loaded;
extern std::string currentCountry;
extern int currencyCount;
extern float travelMulty;
const float 
	WIDTH = (float)sf::VideoMode::getDesktopMode().width, 
	HEIGHT = (float)sf::VideoMode::getDesktopMode().height;
extern sf::RenderWindow win;