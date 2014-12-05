#pragma once
#include "VisibleGameObject.h"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

class Background :
	public VisibleGameObject
{
public:

	/*
	* Constructor for a Background that takes a file for the graphic to be loaded.
	*/
	Background(std::string file);

	/*
	* Destructor for a Background.
	*/
	~Background();

	/*
	* Draws the Background to the window.
	*/
	void draw(sf::RenderWindow& window);

	/*
	* Updates the Background for each frame.
	*/
	void update();
};