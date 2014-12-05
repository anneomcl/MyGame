#pragma once
#include "VisibleGameObject.h"

class PlayerCharacter :
	public VisibleGameObject
{
public:

	/*
	* Constructor for PlayerCharacter.
	*/
	PlayerCharacter();

	/*
	* Destructor for PlayerCharacter.
	*/
	~PlayerCharacter();

	/*
	* Updates the character for each frame.
	*/
	void update(float elapsedTime);

	/*
	* Draws the character on the window.
	*/
	void draw(sf::RenderWindow& rw);

	/*
	* Checks if it is moving left and adjusts x velocity.
	*/
	void checkLeft();

	/*
	* Checks if it is moving right and adjusts x velocity.
	*/
	void checkRight();

	/*
	* Decelerates the x velocity if there is no input.
	*/
	void decelerateX();

	/*
	* Updates the position of the character for each frame.
	*/
	void updatePosition();

	/*
	* Checks bounds of the game and ensures that the player does not move beyond them.
	*/
	void checkXBounds();

	/*
	* If space is pressed, this handles the jump animation.
	*/
	void handleJumps();

	/*
	* Returns type of PlayerCharacter.
	*/
	char * getType();

	/*
	* Vector2f containing the x and y velocity.
	*/
	sf::Vector2f velocity;

	/*
	* Bool indicating whether the player is grounded or in the air.
	*/
	bool grounded;

	/*
	* Number of coins the player has collected.
	*/
	int coins;

	/*
	* Number of extra lives that the player has.
	*/
	int lives;

private:
	sf::Vector2f position; //a vector containing the x and y coordinates of the player
	float maxVelocity; //max velocity for running
	float xAcceleration; //acceleration for running
	float yAcceleration; //acceleration of jumping
	float gravity; //acceleration of gravity
	bool jump; //bool indicating whether there's
	int currJumpFrames; //number of frames that the jump animation has currently used
	int maxJumpFrames; //number of frames jump animation will use until character reaches apex
};