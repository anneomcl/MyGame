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

	void checkLeft();
	void checkRight();
	void decelerateX();
	void updatePosition();
	void checkXBounds();

	sf::Vector2f velocity;

private:
	sf::Vector2f position;
	const sf::Vector2f screenStartPosition;
	float terminalVelocity; //max velocity for falling
	float maxVelocity; //max velocity for running
	float xAcceleration; //acceleration for running
	float yAcceleration; //acceleration of jumping
	float gravity; //acceleration of gravity
	bool jump;
	int currJumpFrames;
	int maxJumpFrames;
};