#include "PlayerCharacter.h"
#include "Game.h"
#include <assert.h>
#include <iostream>
using namespace std;

char * PlayerCharacter::getType()
{
	char * type = "PlayerCharacter";
	return type;
}

PlayerCharacter::PlayerCharacter() :
position(this->getPosition().x, this->getPosition().y),
screenStartPosition(this->getPosition().x, this->getPosition().y),
velocity(0, 0),
terminalVelocity(2.5f),
maxVelocity(500.0f),
gravity(4.0f),
xAcceleration(1.0f),
yAcceleration(3.0f),
jump(0),
grounded(1)
{
	maxJumpFrames = 250;
	currJumpFrames = maxJumpFrames;
	load("C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/PlayerCharacterSprite.png");
	assert(isLoaded());
	getSprite().setOrigin(getSprite().getGlobalBounds().width / 2, getSprite().getGlobalBounds().height / 2);
}

PlayerCharacter::~PlayerCharacter()
{

}

void PlayerCharacter::draw(sf::RenderWindow &rw)
{
	VisibleGameObject::draw(rw);
}

float PlayerCharacter::getVelocity() const
{
	return velocity.x;
}

void PlayerCharacter::checkLeft()
{
	if (velocity.x > -maxVelocity)
		velocity.x -= xAcceleration;
	else if (velocity.x <= maxVelocity)
		velocity.x = -maxVelocity;
}

void PlayerCharacter::checkRight()
{
	if (velocity.x < maxVelocity)
		velocity.x += xAcceleration;
	else if (velocity.x >= maxVelocity)
		velocity.x = maxVelocity;
}

void PlayerCharacter::decelerateX()
{
	if (velocity.x < 0)
		velocity.x += xAcceleration;
	else if (velocity.x > 0)
		velocity.x -= xAcceleration;
	else
		velocity.x = 0;
}

void PlayerCharacter::updatePosition()
{
	position = this->getPosition();
}

void PlayerCharacter::checkXBounds()
{
	if (position.x  < getSprite().getGlobalBounds().width / 2)
	{
		velocity.x = -velocity.x;
	}

	/*else if (position.x >(Game::SCREEN_WIDTH - (getSprite().getGlobalBounds().width / 2)))
	{
		velocity.x = -velocity.x;
	}*/
}

void PlayerCharacter::update(float elapsedTime)
{
	updatePosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		checkLeft();

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		checkRight();

	else
		decelerateX();

	checkXBounds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		jump = true;
		grounded = false;
	}

	if (currJumpFrames > 0 && jump)
	{
		velocity.y -= yAcceleration * (1.2);
		currJumpFrames--;
	}

	else if (currJumpFrames == 0 && jump)
	{
		velocity.y += gravity;
		if (grounded)
		{
			jump = false;
			currJumpFrames = maxJumpFrames;
			velocity.y = 0;
		}
	}

	else if (!grounded)
	{
		velocity.y += gravity;
		if (grounded)
		{
			velocity.y = 0;
		}
	}
	getSprite().move(velocity.x * elapsedTime, velocity.y * elapsedTime);
}