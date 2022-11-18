#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <thread>
#include <chrono>

int manageScreen(std::function<int()> func);
int mainMenu();
int startGame();
int startNokiPhone();
int startNokiMap();
int startGuide();
void loadingScreen();
void currency(sf::Vector2f pos);
void valueManager(char sym, int sum);
void setCurrentCountry(std::string);
extern bool loaded;

const float 
	WIDTH = (float)sf::VideoMode::getDesktopMode().width, 
	HEIGHT = (float)sf::VideoMode::getDesktopMode().height;
extern sf::RenderWindow win;