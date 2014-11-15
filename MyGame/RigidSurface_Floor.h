#pragma once
#include "VisibleGameObject.h"
#include "RigidSurface.h"

class RigidSurface_Floor :
	public RigidSurface
{
public:
	RigidSurface_Floor();
	~RigidSurface_Floor();

	void update(float elapsedTime);
	void draw(sf::RenderWindow& rw);
	char * getType();
};

