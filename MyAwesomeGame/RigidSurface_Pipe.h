#pragma once
#include "VisibleGameObject.h"
#include "RigidSurface.h"

class RigidSurface_Pipe :
	public RigidSurface
{
public:

	/*
	* Constructor for a RigidSurface_Pipe.
	*/
	RigidSurface_Pipe();

	/*
	* Destructor for a RigidSurface_Pipe.
	*/
	~RigidSurface_Pipe();

	/*
	* Updates a RigidSurface_Pipe each frame.
	*/
	void update(float elapsedTime);

	/*
	* Draws the RigidSurface_Pipe to the window.
	*/
	void draw(sf::RenderWindow& rw);

	/*
	* Returns type of RigidSurface_Pipe.
	*/
	char * getType();

};

