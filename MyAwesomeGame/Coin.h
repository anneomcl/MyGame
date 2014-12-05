#pragma once
#include "VisibleGameObject.h"

class Coin :
	public VisibleGameObject
{
public:

	/*
	* Constructor for a Coin.
	*/
	Coin();

	/*
	* Desctructor for a Coin.
	*/
	~Coin();

	/*
	* Updates Coin for each frame.
	*/
	void update(float elapsedTime);

	/*
	* Draws the Coin to the window.
	*/
	void draw(sf::RenderWindow& rw);

	/*
	* Returns the type of Coin.
	*/
	char * getType();

	/*
	* Bool indicating whether the coin is visible or if it has disappeared.
	*/
	bool isVisible;
};