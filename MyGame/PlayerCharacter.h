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
	float _velocity;
	float _maxVelocity;
};