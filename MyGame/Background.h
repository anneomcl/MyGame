#pragma once
#include "VisibleGameObject.h"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

class Background :
	public VisibleGameObject
{
public:
	Background();

	~Background();

	void draw(sf::RenderWindow& window);

	void update();
};