#include "PlayerCharacter.h"
#include "Game.h"
#include <assert.h>

PlayerCharacter::PlayerCharacter() :
_xVelocity(0),
_yVelocity(0),
_grounded(1),
_gravity(1),
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
	return _xVelocity;
}

void PlayerCharacter::update(float elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		_grounded = false;
		_yVelocity -= 1.0f;
		getSprite().move(0, _yVelocity * elapsedTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		_xVelocity -= 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		_xVelocity += 2.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_yVelocity += 2.0f;
	}

	if (_xVelocity > _maxVelocity)
		_xVelocity = _maxVelocity;

	if (_xVelocity < -_maxVelocity)
		_xVelocity = -_maxVelocity;


	sf::Vector2f pos = this->getPosition();

	if (pos.x  < getSprite().getGlobalBounds().width / 2
		|| pos.x >(Game::SCREEN_WIDTH - getSprite().getGlobalBounds().width / 2))
	{
		_xVelocity = -_xVelocity; // Bounce by current velocity in opposite direction
	}

	if (pos.y  < getSprite().getGlobalBounds().height / 2
		|| pos.y >(Game::SCREEN_HEIGHT - getSprite().getGlobalBounds().height / 2))
	{
		_yVelocity = -_yVelocity;
	}

	getSprite().move(_xVelocity * elapsedTime, _yVelocity * elapsedTime);
}