#include "PlayerCharacter.h"
#include "Game.h"
#include <assert.h>

PlayerCharacter::PlayerCharacter() :
_velocity(0),
_maxVelocity(300.0f)
{
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
	return _velocity;
}

void PlayerCharacter::update(float elapsedTime)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		_velocity -= 2.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		_velocity += 2.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_velocity = 0.0f;
	}

	if (_velocity > _maxVelocity)
		_velocity = _maxVelocity;

	if (_velocity < -_maxVelocity)
		_velocity = -_maxVelocity;


	sf::Vector2f pos = this->getPosition();

	if (pos.x  < getSprite().getGlobalBounds().width / 2
		|| pos.x >(Game::SCREEN_WIDTH - getSprite().getGlobalBounds().width / 2))
	{
		_velocity = -_velocity; // Bounce by current velocity in opposite direction
	}

	getSprite().move(_velocity * elapsedTime, 0);
}