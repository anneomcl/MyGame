#pragma once
#include "VisibleGameObject.h"
#include "RigidSurface.h"

class RigidSurface_Brick :
	public RigidSurface
{
public:
	RigidSurface_Brick();
	~RigidSurface_Brick();

	void update(float elapsedTime);
	void draw(sf::RenderWindow& rw);
	char * getType();

	int times_hit;
};

