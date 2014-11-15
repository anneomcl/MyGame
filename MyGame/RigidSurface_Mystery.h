#pragma once
#include "VisibleGameObject.h"
#include "RigidSurface.h"

class RigidSurface_Mystery :
	public RigidSurface
{
public:
	RigidSurface_Mystery();
	~RigidSurface_Mystery();

	void update(float elapsedTime);
	void draw(sf::RenderWindow& rw);
	char * getType();

	int times_hit;
};

