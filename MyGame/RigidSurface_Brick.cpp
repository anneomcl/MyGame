#include <iostream>
#include <assert.h>
#include "RigidSurface_Brick.h"
using namespace std;

RigidSurface_Brick::RigidSurface_Brick()
{
	load("C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/RigidSurface_Brick.png");
	assert(isLoaded());
	getSprite().setOrigin(getSprite().getGlobalBounds().width / 2, getSprite().getGlobalBounds().height / 2);
	times_hit = 0;
}

RigidSurface_Brick::~RigidSurface_Brick()
{

}

char * RigidSurface_Brick::getType()
{
	char * type = "RigidSurface_Brick";
	return type;
}

void RigidSurface_Brick::draw(sf::RenderWindow &rw)
{
	VisibleGameObject::draw(rw);
}

void RigidSurface_Brick::update(float elapsedTime)
{

}