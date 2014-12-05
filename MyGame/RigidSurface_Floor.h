#pragma once
#include "VisibleGameObject.h"
#include "RigidSurface.h"

class RigidSurface_Floor :
	public RigidSurface
{
public:
	/*
	* Constructor for a RigidSurface_Floor.
	*/
	RigidSurface_Floor();

	/*
	* Destructor for a RigidSurface_Floor.
	*/
	~RigidSurface_Floor();

	/*
	* Updates a RigidSurface_Floor each frame.
	*/
	void update(float elapsedTime);

	/*
	* Draws the RigidSurface_Floor to the window.
	*/
	void draw(sf::RenderWindow& rw);

	/*
	* Returns type of RigidSurface_Floor.
	*/
	char * getType();
};

