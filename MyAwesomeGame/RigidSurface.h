#pragma once
#include "VisibleGameObject.h"

class RigidSurface :
	public VisibleGameObject
{
public:

	/*
	* Constructor for a RigidSurface.
	*/
	RigidSurface();

	/*
	* Destructor for a RigidSurface.
	*/
	~RigidSurface();

	/*
	* Updates a RigidSurface each frame.
	*/
	void update(float elapsedTime);

	/*
	* Draws the RigidSurface to the window.
	*/
	void draw(sf::RenderWindow& rw);

	/*
	* Returns type of RigidSurface.
	*/
	char * getType();
};