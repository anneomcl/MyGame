#include "SplashScreen.h"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <iostream>

void SplashScreen::show(sf::RenderWindow & renderWindow)
{
	sf::Texture image;
	if (!image.loadFromFile("C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/MyGameScreen.png"))
	{
		return;
	}

	sf::Sprite sprite(image);

	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;
	while (1)
	{
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed)
			{
				return;
			}
		}
	}
}