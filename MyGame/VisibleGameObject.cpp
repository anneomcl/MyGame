#include "VisibleGameObject.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include <string>
#include <iostream>

VisibleGameObject::VisibleGameObject()
	: _isLoaded(false)
{

}

VisibleGameObject::~VisibleGameObject()
{

}

void VisibleGameObject::load(std::string filename)
{
	if (!_image.loadFromFile(filename))
	{
		
		_filename = "";
		_isLoaded = false;
		return;
	}

	else
	{
		_filename = _filename;
		_sprite.setTexture(_image);
		_isLoaded = true;
	}
}

void VisibleGameObject::draw(sf::RenderWindow &renderWindow)
{
	if (_isLoaded)
	{
		renderWindow.draw(_sprite);
	}
}

void VisibleGameObject::update(float elapsedTime)
{

}

void VisibleGameObject::setPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
	}
}

sf::Vector2f VisibleGameObject::getPosition() const
{
	if (_isLoaded)
	{
		return _sprite.getPosition();
	}

	return sf::Vector2f();
}

sf::Sprite& VisibleGameObject::getSprite()
{
	return _sprite;
}

bool VisibleGameObject::isLoaded() const
{
	return _isLoaded;
}