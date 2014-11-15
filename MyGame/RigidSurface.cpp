#include "RigidSurface.h"
#include "Game.h"
#include <assert.h>
#include <iostream>
using namespace std;

RigidSurface::RigidSurface()
{
	sf::FloatRect bounds = this->getSprite().getGlobalBounds();
	load("C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/RigidSurface_Block.png");
	assert(isLoaded());
	getSprite().setOrigin(bounds.width / 2, bounds.height / 2);
	
}

RigidSurface::~RigidSurface()
{

}

char * RigidSurface::getType()
{
	char * type = "RigidSurface";
	return type;
}

void RigidSurface::draw(sf::RenderWindow &rw)
{
	VisibleGameObject::draw(rw);
}

void RigidSurface::update(float elapsedTime)
{

}