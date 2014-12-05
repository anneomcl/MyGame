#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

class SplashScreen
{
public:

	/*
	* Draws splashscreen image and takes player to the main menu upon any event occurring.
	*/
	void show(sf::RenderWindow& window, std::string file);
};