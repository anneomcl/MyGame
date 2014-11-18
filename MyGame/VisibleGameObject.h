#pragma once
#include <string>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class VisibleGameObject
{
public:
	VisibleGameObject();
	virtual ~VisibleGameObject();

	virtual void load(std::string filename);
	virtual void draw(sf::RenderWindow &window);
	virtual void update(float elapsedTime);

	virtual void setPosition(float x, float y);
	virtual sf::Vector2f getPosition() const;
	virtual bool isLoaded() const;

	virtual char * getType();

//protected:
	sf::Sprite& getSprite();
	std::string _filename;

private:
	sf::Sprite _sprite;
	sf::Texture _image;
	
	bool _isLoaded;
};