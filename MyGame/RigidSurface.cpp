#include "RigidSurface.h"
#include "Game.h"
#include <assert.h>
#include <iostream>
using namespace std;

RigidSurface::RigidSurface()
{
	load("C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/RigidSurface_Block.png");
	assert(isLoaded());
	getSprite().setOrigin(getSprite().getGlobalBounds().width / 2, getSprite().getGlobalBounds().height / 2);
}

RigidSurface::~RigidSurface()
{

}

void RigidSurface::draw(sf::RenderWindow &rw)
{
	VisibleGameObject::draw(rw);
}

void RigidSurface::update(float elapsedTime)
{

}