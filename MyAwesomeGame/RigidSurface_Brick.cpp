#include "RigidSurface_Brick.h"
#include "Game.h"
#include <assert.h>
#include <iostream>
using namespace std;

RigidSurface_Brick::RigidSurface_Brick()
{
	sf::FloatRect bounds = this->getSprite().getGlobalBounds();
	load("C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/RigidSurface_Brick.png");
	getSprite().setOrigin(bounds.width / 2, bounds.height / 2);

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