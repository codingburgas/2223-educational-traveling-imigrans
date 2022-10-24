#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int manageScreen(std::function<int()> func);
int mainMenu();
int startGame();

const int WIDTH = sf::VideoMode::getDesktopMode().width, HEIGHT = sf::VideoMode::getDesktopMode().height;
extern sf::RenderWindow win;