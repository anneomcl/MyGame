#pragma once
#include "VisibleGameObject.h"
#include "RigidSurface.h"

class RigidSurface_Mystery :
	public RigidSurface
{
public:
	/*
	* Constructor for a RigidSurface_Mystery.
	*/
	RigidSurface_Mystery();

	/*
	* Destructor for a RigidSurface_Mystery.
	*/
	~RigidSurface_Mystery();

	/*
	* Updates a RigidSurface_Mystery each frame.
	*/
	void update(float elapsedTime);

	/*
	* Draws the RigidSurface_Mystery to the window.
	*/
	void draw(sf::RenderWindow& rw);

	/*
	* Returns type of RigidSurface_Mystery.
	*/
	char * getType();

	/*
	* Numer of times the mystery block was hit.
	*/
	int times_hit;
};

