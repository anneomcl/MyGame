#include <iostream>
#include <assert.h>
#include "RigidSurface_Floor.h"
using namespace std;

RigidSurface_Floor::RigidSurface_Floor()
{
	load("C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/RigidSurface_Floor.png");
	assert(isLoaded());
	getSprite().setOrigin(getSprite().getGlobalBounds().width / 2, getSprite().getGlobalBounds().height / 2);
}

RigidSurface_Floor::~RigidSurface_Floor()
{

}

char * RigidSurface_Floor::getType()
{
	char * type = "RigidSurface_Floor";
	return type;
}

void RigidSurface_Floor::draw(sf::RenderWindow &rw)
{
	VisibleGameObject::draw(rw);
}

void RigidSurface_Floor::update(float elapsedTime)
{

}