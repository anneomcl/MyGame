#include "VisibleGameObject.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include <string>
#include <iostream>

VisibleGameObject::VisibleGameObject()
	: isLoaded(false)
{

}

VisibleGameObject::~VisibleGameObject()
{

}

char * VisibleGameObject::getType()
{
	return "";
}

void VisibleGameObject::load(std::string filename)
{
	if (!image.loadFromFile(filename))
	{

		filename = "";
		isLoaded = false;
		return;
	}

	else
	{
		filename = filename;
		sprite.setTexture(image);
		isLoaded = true;
	}
}

void VisibleGameObject::draw(sf::RenderWindow &renderWindow)
{
	if (isLoaded)
	{
		renderWindow.draw(sprite);
	}
}

void VisibleGameObject::update(float elapsedTime)
{

}

void VisibleGameObject::setPosition(float x, float y)
{
	if (isLoaded)
	{
		sprite.setPosition(x, y);
	}
}

sf::Vector2f VisibleGameObject::getPosition() const
{
	if (isLoaded)
	{
		return sprite.getPosition();
	}

	return sf::Vector2f();
}

sf::Sprite& VisibleGameObject::getSprite()
{
	return sprite;
}

bool VisibleGameObject::getIsLoaded() const
{
	return isLoaded;
}