#include <iostream>
#include <assert.h>
#include "RigidSurface_Pipe.h"
using namespace std;

RigidSurface_Pipe::RigidSurface_Pipe()
{
	load("C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/RigidSurface_Pipe.png");
	assert(isLoaded());
	getSprite().setOrigin(getSprite().getGlobalBounds().width / 2, getSprite().getGlobalBounds().height / 2);
}

RigidSurface_Pipe::~RigidSurface_Pipe()
{

}

char * RigidSurface_Pipe::getType()
{
	char * type = "RigidSurface_Pipe";
	return type;
}

void RigidSurface_Pipe::draw(sf::RenderWindow &rw)
{
	VisibleGameObject::draw(rw);
}

void RigidSurface_Pipe::update(float elapsedTime)
{

}