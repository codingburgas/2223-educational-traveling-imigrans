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

void loadingScreen();
extern bool loaded;

const int WIDTH = sf::VideoMode::getDesktopMode().width, HEIGHT = sf::VideoMode::getDesktopMode().height;
extern sf::RenderWindow win;