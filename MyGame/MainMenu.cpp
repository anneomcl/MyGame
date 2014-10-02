#include "MainMenu.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"

/*
* show
*/
MainMenu::MenuResult MainMenu::show(sf::RenderWindow& window)
{
	sf::Texture image;
	image.loadFromFile("C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/menu.png");
	sf::Sprite sprite(image);

	MenuItem playButton;
	playButton.rect = sf::Rect<int>(190, 280, 250, 170);
	playButton.action = Play;

	MenuItem exitButton;
	exitButton.rect = sf::Rect<int>(540, 280, 250, 170);
	exitButton.action = Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	window.draw(sprite);
	window.display();

	return getMenuResponse(window);
}

MainMenu::MenuResult MainMenu::handleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for (it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if ((menuItemRect.top + menuItemRect.height > y) &&
			(menuItemRect.top < y) &&
			(menuItemRect.left < x) &&
			(menuItemRect.left + menuItemRect.width > x))
		{
			return (*it).action;
		}
	}
	return Nothing;
}

MainMenu::MenuResult MainMenu::getMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;

	while (1)
	{
		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::MouseButtonPressed)
				return handleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);

			if (menuEvent.type == sf::Event::Closed)
				return Exit;
		}
	}
}