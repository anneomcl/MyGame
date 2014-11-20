#pragma once
#include "VisibleGameObject.h"

class Coin :
	public VisibleGameObject
{
public:
	Coin();
	~Coin();

	void update(float elapsedTime);
	void draw(sf::RenderWindow& rw);
	char * getType();
	bool isVisible;
};