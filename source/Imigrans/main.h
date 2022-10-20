#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int mainMenu();


const int WIDTH = sf::VideoMode::getDesktopMode().width, HEIGHT = sf::VideoMode::getDesktopMode().height;
extern sf::RenderWindow win;