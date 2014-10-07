#pragma once
#include "VisibleGameObject.h"

class PlayerCharacter :
	public VisibleGameObject
{
public:
	PlayerCharacter();
	~PlayerCharacter();

	void update(float elapsedTime);
	void draw(sf::RenderWindow& rw);

	float getVelocity() const;

private:
	float _gravity;
	float _xVelocity;
	float _yVelocity;
	float _maxVelocity;
	bool _grounded;
};