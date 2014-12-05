#pragma once
#include <string>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class VisibleGameObject
{
public:

	/*
	* Constructor for VisibleGameObject
	*/
	VisibleGameObject();

	/*
	* Destructor for VisibleGameObject
	*/
	virtual ~VisibleGameObject();

	/*
	* Loads a file associated with the object.
	*/
	virtual void load(std::string filename);

	/*
	* Draws game object to window.
	*/
	virtual void draw(sf::RenderWindow &window);

	/*
	* Updates the game object for each frame.
	*/
	virtual void update(float elapsedTime);

	/*
	* Sets the position of the object to coordinates (x,y).
	*/
	virtual void setPosition(float x, float y);

	/*
	* Gets the position of the object.
	*/
	virtual sf::Vector2f getPosition() const;

	/*
	* Gets the variable that validates whether the file is loaded or not.
	*/
	virtual bool getIsLoaded() const;

	/*
	* Gets the object type for any VisibleGameObject.
	*/
	virtual char * getType();

	/*
	* Gets the Sprite object associated with the VisibleGameObject.
	*/
	sf::Sprite& getSprite();

	/*
	* Filename associated with graphic for object.
	*/
	std::string filename;

private:
	/*
	* The Sprite object that represents the VisibleGameObject.
	*/
	sf::Sprite sprite;

	/*
	* The image file (Texture) that represents the sprite.
	*/
	sf::Texture image;

	/*
	* Bool indicating whether object file is loaded or not.
	*/
	bool isLoaded;
};