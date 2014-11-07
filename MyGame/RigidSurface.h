#pragma once
#include "VisibleGameObject.h"

class RigidSurface :
	public VisibleGameObject
{
public:
	RigidSurface();
	~RigidSurface();

	void update(float elapsedTime);
	void draw(sf::RenderWindow& rw);
};