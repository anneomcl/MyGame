#pragma once
#include "VisibleGameObject.h"
#include "RigidSurface.h"

class RigidSurface_Pipe :
	public RigidSurface
{
public:
	RigidSurface_Pipe();
	~RigidSurface_Pipe();

	void update(float elapsedTime);
	void draw(sf::RenderWindow& rw);
	char * getType();

	int times_hit;
};

