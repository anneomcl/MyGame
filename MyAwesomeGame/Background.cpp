#include "Background.h"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <iostream>
#include <assert.h>

Background::Background(std::string file)
{
	load(file);
	//"C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/Background_condensed.png"
}

Background::~Background()
{

}

void Background::draw(sf::RenderWindow & rw)
{
	VisibleGameObject::draw(rw);
}

void Background::update()
{

}