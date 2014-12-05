#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <list>

class MainMenu
{
public:

	/*
	* MenuResult is the result of an event in the main menu.
	*/
	enum MenuResult { Nothing, Exit, Play };

	/*
	* MenuItem is struct with button coordinates and an associated action on the button.
	*/
	struct MenuItem
	{
		sf::Rect<int> rect;
		MenuResult action;
	};

	/*
	* This draws the buttons onto the menu image and starts the polling loop.
	*/
	MenuResult show(sf::RenderWindow& window);

private:

	/*
	* This constantly polls for clicks on buttons, determining whether to exit or do button action.
	*/
	MenuResult getMenuResponse(sf::RenderWindow& window);

	/*
	* This handles all clicking events that are polled. It checks if a given click occurred within the button coordinates.
	*/
	MenuResult handleClick(int x, int y);

	/*
	* This is a list of all buttons associated with the main menu.
	*/
	std::list<MenuItem> _menuItems;
};