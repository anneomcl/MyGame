#include <iostream>
#include <assert.h>
#include "RigidSurface_Mystery.h"
using namespace std;

RigidSurface_Mystery::RigidSurface_Mystery()
{
	load("C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/RigidSurface_Block.png");
	getSprite().setOrigin(getSprite().getGlobalBounds().width / 2, getSprite().getGlobalBounds().height / 2);
	times_hit = 0;
}

RigidSurface_Mystery::~RigidSurface_Mystery()
{

}

char * RigidSurface_Mystery::getType()
{
	char * type = "RigidSurface_Mystery";
	return type;
}

void RigidSurface_Mystery::draw(sf::RenderWindow &rw)
{
	VisibleGameObject::draw(rw);
}

void RigidSurface_Mystery::update(float elapsedTime)
{

}