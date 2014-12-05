#pragma once
#include "VisibleGameObject.h"
#include "RigidSurface.h"

class RigidSurface_Brick :
	public RigidSurface
{
public:
	/*
	* Constructor for a RigidSurface_Brick.
	*/
	RigidSurface_Brick();

	/*
	* Destructor for a RigidSurface_Brick.
	*/
	~RigidSurface_Brick();

	/*
	* Updates a RigidSurface_Brick each frame.
	*/
	void update(float elapsedTime);

	/*
	* Draws the RigidSurface_Brick to the window.
	*/
	void draw(sf::RenderWindow& rw);

	/*
	* Returns type of RigidSurface_Brick.
	*/
	char * getType();

	/*
	* Number of times that the block has been hit.
	*/
	int times_hit;
};

