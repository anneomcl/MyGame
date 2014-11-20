#include "Coin.h"
#include "Game.h"
#include <assert.h>
#include <iostream>
using namespace std;

Coin::Coin()
{
	isVisible = true;
	sf::FloatRect bounds = this->getSprite().getGlobalBounds();
	load("C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/coin.png");
	assert(isLoaded());
	getSprite().setOrigin(bounds.width / 2, bounds.height / 2);

}

Coin::~Coin()
{

}

char * Coin::getType()
{
	char * type = "Coin";
	return type;
}

void Coin::draw(sf::RenderWindow &rw)
{
	if (this->isVisible)
		VisibleGameObject::draw(rw);
}

void Coin::update(float elapsedTime)
{

}