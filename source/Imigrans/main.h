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
extern bool loaded;

const int WIDTH = sf::VideoMode::getDesktopMode().width, HEIGHT = sf::VideoMode::getDesktopMode().height;
extern sf::RenderWindow win;